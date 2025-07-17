
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
        error_output_ << "Interpretation successful." << std::endl;
    
}

bool Interpreter::verify() {

    std::map<std::string, cvc5::Term> current_semantics = semantics_.back();

    cvc5::Term q1_1 = qubits_.at("_q1_1_");
    cvc5::Term output = current_semantics.at("_q1_1_");

    cvc5::Term zero_to_zero = tm_.mkTerm(cvc5::Kind::IMPLIES, {q1_1, output});

    solver_.assertFormula(tm_.mkTerm(cvc5::Kind::NOT, {zero_to_zero}));

    cvc5::Result result = solver_.checkSat();

    std::cout << zero_to_zero << std::endl;
    std::cout << "Result: " << result << std::endl;


    return true;
}