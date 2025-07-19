
#include "Verifier_Bitwuzla.h"  


#define RED "\033[1;31m"
#define RESET "\033[0m"


Verifier_Bitwuzla::Verifier_Bitwuzla(const std::shared_ptr<Program>& program, 
                         std::ostream& error_output) 
    : program_(program),
      error_output_(error_output) {
    options_.set(bitwuzla::Option::PRODUCE_MODELS, true);
    options_.set(bitwuzla::Option::SAT_SOLVER, "cadical");
    bool_sort_ = tm_.mk_bool_sort();

}

std::shared_ptr<Verifier_Bitwuzla> Verifier_Bitwuzla::make_verifier(const std::shared_ptr<Program>& program, 
                                                           std::ostream& error_output) {
    return std::shared_ptr<Verifier_Bitwuzla>(new Verifier_Bitwuzla(program, error_output));
}

void Verifier_Bitwuzla::interpret() {
    semantics_.clear();
    try {
        for (size_t i = 0; i < program_ -> get_statements().size(); i++) {

            const auto& stmt = program_ -> get_statements()[i];
            std::map<std::string, bitwuzla::Term> current_semantics =  i == 0 ? 
                std::map<std::string, bitwuzla::Term>() : semantics_.back();

            switch (stmt->get_type()) {
                case Stmt::Stmt_Type::BORROW: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& borrow_stmt = std::get<Stmt::Stmt_Borrow>(tmp);
                    int size = borrow_stmt.register_ -> get_size() -> get_number();
                    for (int j = 1; j <= size; j++) {
                        const std::string& qubit_name = borrow_stmt.register_ -> get_name() + std::to_string(j) + "_";
                        current_semantics[qubit_name] = qubits_[qubit_name] = tm_.mk_const(bool_sort_, qubit_name);
                    }
                    break;
                }
                case Stmt::Stmt_Type::ALLOC: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& alloc_stmt = std::get<Stmt::Stmt_Alloc>(tmp);
                    int size = alloc_stmt.register_ -> get_size() -> get_number();
                    for (int j = 1; j <= size; j++) {
                        const std::string& qubit_name = alloc_stmt.register_ -> get_name() + std::to_string(j) + "_";
                        current_semantics[qubit_name] = qubits_[qubit_name] = tm_.mk_false();
                    }
                    break;
                }
                case Stmt::Stmt_Type::X: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& x_stmt = std::get<Stmt::Stmt_X>(tmp);
                    const std::string& qubit_name = x_stmt.target_ -> get_name() + std::to_string(x_stmt.target_ -> get_size() -> get_number()) + "_";

                    current_semantics[qubit_name] = tm_.mk_term(bitwuzla::Kind::NOT, {current_semantics[qubit_name]});
                    
                    break;
                }
                case Stmt::Stmt_Type::CNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& cnot_stmt = std::get<Stmt::Stmt_CNOT>(tmp);
                    const std::string& control_name = cnot_stmt.control_ -> get_name() + std::to_string(cnot_stmt.control_ -> get_size() -> get_number()) + "_";
                    const std::string& target_name = cnot_stmt.target_ -> get_name() + std::to_string(cnot_stmt.target_ -> get_size() -> get_number()) + "_";

                    current_semantics[target_name] = tm_.mk_term(bitwuzla::Kind::XOR, {current_semantics[control_name], current_semantics[target_name]});
                    break;
                }
                case Stmt::Stmt_Type::CCNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& ccnot_stmt = std::get<Stmt::Stmt_CCNOT>(tmp);
                    const std::string& control1_name = ccnot_stmt.control1_ -> get_name() + std::to_string(ccnot_stmt.control1_ -> get_size() -> get_number()) + "_";
                    const std::string& control2_name = ccnot_stmt.control2_ -> get_name() + std::to_string(ccnot_stmt.control2_ -> get_size() -> get_number()) + "_";
                    const std::string& target_name = ccnot_stmt.target_ -> get_name() + std::to_string(ccnot_stmt.target_ -> get_size() -> get_number()) + "_";

                    bitwuzla::Term tmp_term = tm_.mk_term(bitwuzla::Kind::AND, {current_semantics[control1_name], current_semantics[control2_name]});
                    current_semantics[target_name] = tm_.mk_term(bitwuzla::Kind::XOR, {tmp_term, current_semantics[target_name]});
                    break;
                }
                case Stmt::Stmt_Type::REL:
                    break;
                default:
                    throw std::runtime_error("");
            }

            semantics_.push_back(current_semantics);
        }
        std::map<std::string, bitwuzla::Term> current_semantics = semantics_.back();
        for (const auto& [name, term] : current_semantics) {
            error_output_ << name << ": " << term.str() << std::endl;
        }
    }
    catch (const std::exception& e) {
        error_output_ << RED << e.what() << std::endl;
        error_output_ << RED << "[Interpretation failed] Program not preprocessed." << RESET << std::endl;
        throw;
    }
    
}

bool Verifier_Bitwuzla::verify() {

    std::vector<std::shared_ptr<Stmt> > stmts = program_ -> get_statements();

    bitwuzla::Bitwuzla bitwuzla(tm_, options_);
    bitwuzla::Result result;

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
                
                std::map<std::string, bitwuzla::Term> current_semantics = j == stmts.size() ? semantics_.back() : semantics_[j];

                for (int idx = 1;idx <= size; idx++) {
                    std::string qubit_name = name + std::to_string(idx) + "_";
                    std::cout << "Verifying borrowed qubit: " << qubit_name << std::endl;
                    

                    bitwuzla::Term qubit_term = qubits_[qubit_name];
                    bitwuzla::Term final_term = current_semantics[qubit_name];


                    /* 
                        qubit_term = false ==> final_term = false
                        equivalent to: final_term ==> qubit_term
                        equivalent to: neg (final_term ==> qubit_term) is unSatisfiable
                    */
                    bitwuzla.push(1);
                    
                    // first, assert qubit_term = false
                    // bitwuzla.assert_formula(tm_.mk_term(bitwuzla::Kind::XOR, {qubit_term, tm_.mk_true()}));
                    // result = bitwuzla.check_sat(); // definitely satisfiable
                    
                    // bitwuzla.push(1);
                    // // then, assert final_term = true is unsatisfiable
                    // bitwuzla.assert_formula(tm_.mk_term(bitwuzla::Kind::XOR, {final_term, tm_.mk_false()}));
                    // result = bitwuzla.check_sat();
                    bitwuzla.assert_formula(tm_.substitute_term(final_term, {{qubit_term, tm_.mk_false()}}));
                    result = bitwuzla.check_sat();

                    if (result == bitwuzla::Result::SAT) {
                        throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": borrowed qubit " + qubit_name + " is not safely uncomputed.");
                    }
                    if (result != bitwuzla::Result::UNSAT) {
                        throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": safe uncomputation of borrowed qubit " + qubit_name + " cannot be verified.");
                    }

                    bitwuzla.pop(1);

                    
                    for (const auto& [name, term] : current_semantics) {
                        if (name == qubit_name) continue;
                        bitwuzla.push(1);

                        /*
                            when_false == when_true 
                            if and only if when_false xor when_true is unsatisfiable
                        */
                        bitwuzla::Term when_false = tm_.substitute_term(term, {{qubit_term, tm_.mk_false()}});
                        bitwuzla::Term when_true = tm_.substitute_term(term, {{qubit_term, tm_.mk_true()}});
                        

                        bitwuzla.assert_formula(tm_.mk_term(bitwuzla::Kind::XOR, {when_false, when_true}));
                        result = bitwuzla.check_sat();

                        if (result == bitwuzla::Result::SAT) {
                            throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": borrowed qubit " + qubit_name + " is not safely uncomputed.");
                        }
                        if (result != bitwuzla::Result::UNSAT) {
                            throw std::runtime_error("Line " + std::to_string(stmts[i]->get_lineno()) + ": safe uncomputation of borrowed qubit " + qubit_name + " cannot be verified.");
                        }

                        bitwuzla.pop(1);
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

    // bitwuzla::Bitwuzla bitwuzla(tm_, options_);

    // // 2. 定义布尔变量
    // // Bitwuzla 中的布尔值是 1 位宽的位向量。
    // // bitwuzla::Sort bool_sort = tm_.mk_bool_sort();
    // bitwuzla::Term a = tm_.mk_const(bool_sort_, "a");
    // bitwuzla::Term b = tm_.mk_const(bool_sort_, "b");
    // bitwuzla::Term c = tm_.mk_const(bool_sort_, "c");

    // // assert a == false
    // bitwuzla.assert_formula(tm_.mk_term(bitwuzla::Kind::XOR, {a, tm_.mk_true()}));

    // for (const auto& term : bitwuzla.get_assertions()) {
    //     std::cout << term.str() << std::endl;
    // }
    // bitwuzla::Result result = bitwuzla.check_sat(); 
    // std::cout << std::to_string(result) << std::endl;
    // std::cout << std::endl;

    // bitwuzla.push(1);

    // // in addition assert a == true
    // bitwuzla.assert_formula(tm_.mk_term(bitwuzla::Kind::XOR, {a, tm_.mk_false()}));

    // for (const auto& term : bitwuzla.get_assertions()) {
    //     std::cout << term.str() << std::endl;
    // }
    // result = bitwuzla.check_sat(); 
    // std::cout << std::to_string(result) << std::endl;
    // std::cout << std::endl;


    // bitwuzla.pop(1);

    // result = bitwuzla.check_sat(); 

    // std::cout << std::to_string(result) << std::endl;

    return true;
}