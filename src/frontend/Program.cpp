
#include "Program.h"
#include <map>


std::shared_ptr<Program> Program::make_program(const std::vector<std::shared_ptr<Stmt> >& statements) {
    return std::make_shared<Program>(Program(statements));
}

Program::Program(const std::vector<std::shared_ptr<Stmt> >& statements)
    : statements_(statements) {}

void Program::print_program(std::ostream& os) const {
    for (const auto& stmt : statements_) {
        stmt->print_stmt(os);
        os << std::endl;
    }
}

std::vector<std::shared_ptr<Stmt> > Program::get_statements() const {
    return statements_;
}

bool Program::eliminate_let_statements() {
    std::vector<std::shared_ptr<Stmt> > new_statements;

    size_t i = 0;
    for (; i < statements_.size(); i++) {
        if (statements_[i] -> get_type() == Stmt::Stmt_Type::LET) 
            break;
        
        new_statements.push_back(statements_[i]);
    }

    if (i == statements_.size()) {
        statements_ = new_statements; // no LET statement found
        return false;
    }

    std::string id = std::get<Stmt::Stmt_Let>(statements_[i] -> get_stmt()).id_;
    auto expr = std::get<Stmt::Stmt_Let>(statements_[i] -> get_stmt()).expr_;

    i++;

    /*
        search for the next LET statement with the same id
    */
    for (; i < statements_.size(); i++) {
        if (statements_[i]->get_type() == Stmt::Stmt_Type::LET) {
            if (std::get<Stmt::Stmt_Let>(statements_[i] -> get_stmt()).id_ == id) { 
                /*
                    if we find a LET statement with the same id,
                    we substitute the previous one with the current one
                    and break
                */
                new_statements.push_back(statements_[i++] -> substitute(id, expr));
                break;
            }
        }

        new_statements.push_back(statements_[i] -> substitute(id, expr));
    }

    // add remaining statements
    for (; i < statements_.size(); i++) {
        new_statements.push_back(statements_[i]);
    }

    statements_ = new_statements;
    return true;

}


bool Program::eliminate_for_statements() {
    std::vector<std::shared_ptr<Stmt> > new_statements;

    size_t i = 0;
    for (; i < statements_.size(); i++) {
        if (statements_[i]->get_type() == Stmt::Stmt_Type::FOR) {
            break;
        }
        new_statements.push_back(statements_[i]);
    }
    if (i == statements_.size()) {
        statements_ = new_statements; // no FOR statement found
        return false;
    }

    std::string id = std::get<Stmt::Stmt_For>(statements_[i] -> get_stmt()).id_;
    int start = std::get<Stmt::Stmt_For>(statements_[i] -> get_stmt()).start_ -> evaluate();
    int end = std::get<Stmt::Stmt_For>(statements_[i] -> get_stmt()).end_ -> evaluate();

    for (int j = start; j < end; j++) {
        std::vector<std::shared_ptr<Stmt> > body = std::get<Stmt::Stmt_For>(statements_[i] -> get_stmt()).body_;
        for (auto& stmt : body) {
            new_statements.push_back(stmt -> substitute(id, Expr::make_number(j)));
        }
    }

    i++;
    // add remaining statements
    for (; i < statements_.size(); i++) {
        new_statements.push_back(statements_[i]);
    }
    statements_ = new_statements;

    return true;
}


void Program::evaluate() {
    std::vector<std::shared_ptr<Stmt> > evaluated_statements;

    for (const auto& stmt : statements_) {
        evaluated_statements.push_back(stmt -> evaluate());
    }

    statements_ = evaluated_statements;
}


bool Program::rename_borrow_alloc(int layer) {
    size_t i = 0;
    for (; i < statements_.size(); i++) {
            if (statements_[i]->get_type() == Stmt::Stmt_Type::BORROW &&
                std::get<Stmt::Stmt_Borrow>(statements_[i] -> get_stmt()).register_ -> get_name()[0] != '_')
                break;
            if (statements_[i]->get_type() == Stmt::Stmt_Type::ALLOC &&
                std::get<Stmt::Stmt_Alloc>(statements_[i] -> get_stmt()).register_ -> get_name()[0] != '_') {
                break;
        }
    }

    if (i == statements_.size()) {
        return false; // no BORROW or ALLOC statement found
    }
    std::string name = statements_[i]->get_type() == Stmt::Stmt_Type::BORROW ?
    std::get<Stmt::Stmt_Borrow>(statements_[i] -> get_stmt()).register_ -> get_name() :
    std::get<Stmt::Stmt_Alloc>(statements_[i] -> get_stmt()).register_ -> get_name();
    
    int cnt = 0;
    size_t j = i + 1;

    for (;j < statements_.size(); j++) {

        if (statements_[j] -> get_type() == Stmt::Stmt_Type::BORROW) {
            
            if (std::get<Stmt::Stmt_Borrow>(statements_[j] -> get_stmt()).register_ -> get_name() == name)
                cnt++;

        }
        if (statements_[j] -> get_type() == Stmt::Stmt_Type::ALLOC) {
            
            if (std::get<Stmt::Stmt_Alloc>(statements_[j] -> get_stmt()).register_ -> get_name() == name)
                cnt++;

        }
        if (statements_[j]->get_type() == Stmt::Stmt_Type::REL &&
            std::get<Stmt::Stmt_Rel>(statements_[j] -> get_stmt()).id_ == name) {

            if (cnt == 0) break;
            cnt--;

        }
    }


    const auto& sub_program = make_program(
        std::vector<std::shared_ptr<Stmt> >(statements_.begin() + i + 1, statements_.begin() + j)
    );

    if (sub_program -> rename_borrow_alloc(layer + 1))  {
        for (size_t k = i + 1; k < j; k++) {
            statements_[k] = sub_program -> statements_[k - i - 1];
        }
        return true;
    }

    statements_[i] = statements_[i] -> substitute_reg(name, "_q" + std::to_string(layer) + "_");
    if (j < statements_.size())
        statements_[j] = statements_[j] -> substitute_reg(name, "_q" + std::to_string(layer) + "_");
    
    for (size_t k = i + 1; k < j; k++) {

        statements_[k] = statements_[k] -> substitute_reg(name, "_q" + std::to_string(layer) + "_");
    
    }

    return true;
}


void Program::check_free_name() const {
    for (const auto& stmt : statements_) {
        try{
            switch (stmt->get_type()) {
                case Stmt::Stmt_Type::BORROW: {
                    if (std::get<Stmt::Stmt_Borrow>(stmt -> get_stmt()).register_ -> get_name()[0] != '_') {
                        throw std::runtime_error(""); // found a register name that does not start with '_'
                    }
                    break;
                }
                case Stmt::Stmt_Type::ALLOC: {
                    if (std::get<Stmt::Stmt_Alloc>(stmt -> get_stmt()).register_ -> get_name()[0] != '_') {
                        throw std::runtime_error(""); // found a register name that does not start with '_'
                    }
                    break;
                }
                case Stmt::Stmt_Type::REL: {
                    if (std::get<Stmt::Stmt_Rel>(stmt -> get_stmt()).id_[0] != '_') {
                        throw std::runtime_error(""); // found a relation id that does not start with '_'
                    }
                    break;
                }
                case Stmt::Stmt_Type::X: {
                    if (std::get<Stmt::Stmt_X>(stmt->get_stmt()).target_ -> get_name()[0] != '_') {
                        throw std::runtime_error(""); // found a target register name that does not start with '_'
                    }
                    break;
                }
                case Stmt::Stmt_Type::CNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& cnot_stmt = std::get<Stmt::Stmt_CNOT>(tmp);
                    if (cnot_stmt.control_ -> get_name()[0] != '_' ||
                        cnot_stmt.target_ -> get_name()[0] != '_') {
                        throw std::runtime_error(""); // found a control or target register name that does not start with '_'
                    }
                    break;
                }   
                case Stmt::Stmt_Type::CCNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& ccnot_stmt = std::get<Stmt::Stmt_CCNOT>(tmp);
                    if (ccnot_stmt.control1_ -> get_name()[0] != '_' ||
                        ccnot_stmt.control2_ -> get_name()[0] != '_' ||
                        ccnot_stmt.target_ -> get_name()[0] != '_') {
                        throw std::runtime_error(""); // found a control or target register name that does not start with '_'
                    }
                    break;
                }
                case Stmt::Stmt_Type::FOR: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& for_stmt = std::get<Stmt::Stmt_For>(tmp);
                    make_program(for_stmt.body_) -> check_free_name();
                    break;
                }
                default: 
                    break; // other statement types do not have register names to check
            }
        }
        catch (const std::runtime_error&) {
            throw std::runtime_error("Line " + std::to_string(stmt->get_lineno()) + ": register not allocated or borrowed.");
        }
    }
}


void Program::check_out_range() const {

    std::map<std::string, int> range;

    for (const auto& stmt : statements_) {
        try {
            switch (stmt -> get_type()) {
                case Stmt::Stmt_Type::BORROW: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& reg = std::get<Stmt::Stmt_Borrow>(tmp).register_;
                    range[reg -> get_name()] = reg -> get_size() -> evaluate();
                    break;
                }
                case Stmt::Stmt_Type::ALLOC: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& reg = std::get<Stmt::Stmt_Alloc>(tmp).register_;
                    range[reg -> get_name()] = reg -> get_size() -> evaluate();
                    break;
                }
                case Stmt::Stmt_Type::X: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& reg = std::get<Stmt::Stmt_X>(tmp).target_;
                    if (range[reg -> get_name()] < reg -> get_size() -> evaluate()) {
                        throw std::runtime_error(""); // register not found in range map
                    }
                    if (reg -> get_size() -> evaluate() <= 0) {
                        throw std::runtime_error(""); // register size is not positive
                    }
                    break;
                }
                case Stmt::Stmt_Type::CNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& cnot_stmt = std::get<Stmt::Stmt_CNOT>(tmp);
                    if (range[cnot_stmt.control_ -> get_name()] < cnot_stmt.control_ -> get_size() -> evaluate() ||
                        range[cnot_stmt.target_ -> get_name()] < cnot_stmt.target_ -> get_size() -> evaluate()) {
                        throw std::runtime_error(""); // control or target register not found in range map
                    }
                    if (cnot_stmt.control_ -> get_size() -> evaluate() <= 0 ||
                        cnot_stmt.target_ -> get_size() -> evaluate() <= 0) {
                        throw std::runtime_error(""); // control or target register size is not positive
                    }
                    break;
                }
                case Stmt::Stmt_Type::CCNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& ccnot_stmt = std::get<Stmt::Stmt_CCNOT>(tmp);
                    if (range[ccnot_stmt.control1_ -> get_name()] < ccnot_stmt.control1_ -> get_size() -> evaluate() ||
                        range[ccnot_stmt.control2_ -> get_name()] < ccnot_stmt.control2_ -> get_size() -> evaluate() ||
                        range[ccnot_stmt.target_ -> get_name()] < ccnot_stmt.target_ -> get_size() -> evaluate()) {
                        throw std::runtime_error(""); // control or target register not found in range map
                    }
                    if (ccnot_stmt.control1_ -> get_size() -> evaluate() <= 0 ||
                        ccnot_stmt.control2_ -> get_size() -> evaluate() <= 0 ||
                        ccnot_stmt.target_ -> get_size() -> evaluate() <= 0) {
                        throw std::runtime_error(""); // control or target register size is not positive
                    }
                    break;
                }
                case Stmt::Stmt_Type::REL: {
                    range[std::get<Stmt::Stmt_Rel>(stmt -> get_stmt()).id_] = 0; 
                    break;
                }
                default:
                    break;
            }
        }
        catch (const std::exception& ex) {
            throw std::runtime_error("Line " + std::to_string(stmt->get_lineno()) + ": register out of range.");
        }
    }
}


void Program::check_disjoint() const {
    for (const auto& stmt : statements_) {
        try {
            switch (stmt -> get_type()) {
                case Stmt::Stmt_Type::CNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& cnot_stmt = std::get<Stmt::Stmt_CNOT>(tmp);
                    if (cnot_stmt.control_ -> get_name() == cnot_stmt.target_ -> get_name() &&
                        cnot_stmt.control_ -> get_size() -> evaluate() == cnot_stmt.target_ -> get_size() -> evaluate()) {
                        throw std::runtime_error(""); // control and target registers are not disjoint
                    }
                    break;
                }
                case Stmt::Stmt_Type::CCNOT: {
                    const auto& tmp = stmt -> get_stmt();
                    const auto& ccnot_stmt = std::get<Stmt::Stmt_CCNOT>(tmp);
                    if ((ccnot_stmt.control1_ -> get_name() == ccnot_stmt.control2_ -> get_name() &&
                         ccnot_stmt.control1_ -> get_size() -> evaluate() == ccnot_stmt.control2_ -> get_size() -> evaluate()) ||
                        (ccnot_stmt.control1_ -> get_name() == ccnot_stmt.target_ -> get_name() &&
                         ccnot_stmt.control1_ -> get_size() -> evaluate() == ccnot_stmt.target_ -> get_size() -> evaluate()) ||
                        (ccnot_stmt.control2_ -> get_name() == ccnot_stmt.target_ -> get_name() &&
                         ccnot_stmt.control2_ -> get_size() -> evaluate() == ccnot_stmt.target_ -> get_size() -> evaluate())) {
                        throw std::runtime_error(""); // control and target registers are not disjoint
                    }
                    break;
                }
                default:
                    break; // other statement types do not have register names to check
            }
        }
        catch (const std::runtime_error&) {
            throw std::runtime_error("Line " + std::to_string(stmt->get_lineno()) + ": register are not disjoint.");
        }
    }
}