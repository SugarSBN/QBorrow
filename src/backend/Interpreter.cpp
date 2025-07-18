
#include "Interpreter.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"

Interpreter::Interpreter(const std::shared_ptr<Program>& program, 
                         std::ostream& error_output) 
    : program_(program),
      error_output_(error_output) {
    solver_.setOption("produce-models", "true");
    qubits_.clear();
}

std::shared_ptr<Interpreter> Interpreter::make_interpreter(const std::shared_ptr<Program>& program, 
                                                           std::ostream& error_output) {
    return std::shared_ptr<Interpreter>(new Interpreter(program, error_output));
}



void Interpreter::interpret() {
    semantics_.clear();
    try {
        for (size_t i = 0; i < program_->get_statements().size(); i++) {

            const auto& stmt = program_->get_statements()[i];
            std::map<std::string, cvc5::Term> current_semantics =  i == 0 ? 
                std::map<std::string, cvc5::Term>() : semantics_.back();

            switch (stmt->get_type()) {
                case Stmt::Stmt_Type::BORROW: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& borrow_stmt = std::get<Stmt::Stmt_Borrow>(tmp);
                    int size = borrow_stmt.register_ -> get_size() -> get_number();
                    for (int j = 1; j <= size; j++) {
                        const std::string& qubit_name = borrow_stmt.register_ -> get_name() + std::to_string(j) + "_";
                        current_semantics[qubit_name] = qubits_[qubit_name] = tm_.mkConst(tm_.getBooleanSort(), qubit_name);
                    }
                    break;
                }
                case Stmt::Stmt_Type::ALLOC: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& alloc_stmt = std::get<Stmt::Stmt_Alloc>(tmp);
                    int size = alloc_stmt.register_ -> get_size() -> get_number();
                    for (int j = 1; j <= size; j++) {
                        const std::string& qubit_name = alloc_stmt.register_ -> get_name() + std::to_string(j) + "_";
                        current_semantics[qubit_name] = qubits_[qubit_name] = tm_.mkFalse();
                    }
                    break;
                }
                case Stmt::Stmt_Type::X: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& x_stmt = std::get<Stmt::Stmt_X>(tmp);
                    const std::string& qubit_name = x_stmt.target_ -> get_name() + std::to_string(x_stmt.target_ -> get_size() -> get_number()) + "_";

                    current_semantics[qubit_name] = tm_.mkTerm(cvc5::Kind::NOT, {current_semantics[qubit_name]});
                    
                    break;
                }
                case Stmt::Stmt_Type::CNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& cnot_stmt = std::get<Stmt::Stmt_CNOT>(tmp);
                    const std::string& control_name = cnot_stmt.control_ -> get_name() + std::to_string(cnot_stmt.control_ -> get_size() -> get_number()) + "_";
                    const std::string& target_name = cnot_stmt.target_ -> get_name() + std::to_string(cnot_stmt.target_ -> get_size() -> get_number()) + "_";

                    current_semantics[target_name] = tm_.mkTerm(cvc5::Kind::XOR, {current_semantics[control_name], current_semantics[target_name]});
                    break;
                }
                case Stmt::Stmt_Type::CCNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& ccnot_stmt = std::get<Stmt::Stmt_CCNOT>(tmp);
                    const std::string& control1_name = ccnot_stmt.control1_ -> get_name() + std::to_string(ccnot_stmt.control1_ -> get_size() -> get_number()) + "_";
                    const std::string& control2_name = ccnot_stmt.control2_ -> get_name() + std::to_string(ccnot_stmt.control2_ -> get_size() -> get_number()) + "_";
                    const std::string& target_name = ccnot_stmt.target_ -> get_name() + std::to_string(ccnot_stmt.target_ -> get_size() -> get_number()) + "_";

                    cvc5::Term tmp_term = tm_.mkTerm(cvc5::Kind::AND, {current_semantics[control1_name], current_semantics[control2_name]});
                    current_semantics[target_name] = tm_.mkTerm(cvc5::Kind::XOR, {tmp_term, current_semantics[target_name]});
                    break;
                }
                case Stmt::Stmt_Type::REL:
                    break;
                default:
                    throw std::runtime_error("");
            }

            semantics_.push_back(current_semantics);
        }
        std::map<std::string, cvc5::Term> current_semantics = semantics_.back();
        for (const auto& [name, term] : current_semantics) {
            error_output_ << name << ": " << term.toString() << std::endl;
        }
    }
    catch (const std::exception& e) {
        error_output_ << RED << e.what() << std::endl;
        error_output_ << RED << "[Interpretation failed] Program not preprocessed." << RESET << std::endl;
        throw;
    }
    
}

bool Interpreter::verify() {
    
    std::vector<std::shared_ptr<Stmt> > stmts = program_->get_statements();

    try {
        for (size_t i = 0;i < stmts.size();i++) {

            if (stmts[i] -> get_type() == Stmt::Stmt_Type::BORROW &&
                std::get<Stmt::Stmt_Borrow>(stmts[i] -> get_stmt()).need_check_) {


                std::string name = std::get<Stmt::Stmt_Borrow>(stmts[i] -> get_stmt()).register_ -> get_name();
                int size = std::get<Stmt::Stmt_Borrow>(stmts[i] -> get_stmt()).register_ -> get_size() -> get_number();
                
                size_t j = i + 1;
                while (j < stmts.size() && 
                    (stmts[j] -> get_type() != Stmt::Stmt_Type::REL || 
                     std::get<Stmt::Stmt_Rel>(stmts[j] -> get_stmt()).id_ != name)) 
                    j++;
                
                std::map<std::string, cvc5::Term> current_semantics = j == stmts.size() ? semantics_.back() : semantics_[j];

                for (int idx = 1;idx <= size; idx++) {
                    std::string qubit_name = name + std::to_string(idx) + "_";
                    std::cout << "Verifying borrowed qubit: " << qubit_name << std::endl;
                    

                    cvc5::Term qubit_term = qubits_[qubit_name];
                    cvc5::Term final_term = current_semantics[qubit_name];
                    /* 
                        qubit_term = false ==> final_term = false
                        equivalent to: final_term ==> qubit_term
                        equivalent to: neg (final_term ==> qubit_term) is unSatisfiable
                    */
                    solver_.resetAssertions();
                    solver_.assertFormula(tm_.mkTerm(cvc5::Kind::NOT, {tm_.mkTerm(cvc5::Kind::IMPLIES, {final_term, qubit_term})}));

                    cvc5::Result result = solver_.checkSat();
                    if (result.isSat()) {
                        throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": borrowed qubit " + qubit_name + " is not safely uncomputed.");
                    }
                    if (!result.isUnsat()) {
                        throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": safe uncomputation of borrowed qubit " + qubit_name + " cannot be verified.");
                    } 

                    
                    for (const auto& [name, term] : current_semantics) {

                        if (name == qubit_name) continue;

                        /*
                            when_false == when_true 
                            if and only if when_false xor when_true is unsatisfiable
                        */
                        cvc5::Term when_false = term.substitute({qubit_term}, tm_.mkFalse());
                        cvc5::Term when_true = term.substitute({qubit_term}, tm_.mkTrue());
                        solver_.resetAssertions();
                        solver_.assertFormula(tm_.mkTerm(cvc5::Kind::XOR, {when_false, when_true}));
                        
                        result = solver_.checkSat();

                        if (result.isSat()) {
                            throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": borrowed qubit " + qubit_name + " is not safely uncomputed.");
                        }
                        if (!result.isUnsat()) {
                            throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": safe uncomputation of borrowed qubit " + qubit_name + " cannot be verified.");
                        } 
                    }
                    
                }
            }
        }
        return true;
    }
    catch (const std::exception& e) {
        error_output_ << RED << e.what() << std::endl;
        error_output_ << RED << "[Verification failed]" << RESET << std::endl;
        return false;
    }
}