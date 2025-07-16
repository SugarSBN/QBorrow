
#include "Program.h"

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


bool Program::rename_borrow_alloc() {
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

    std::string name = std::get<Stmt::Stmt_Borrow>(statements_[i] -> get_stmt()).register_ -> get_name();
    int layer = 0;
    size_t j = i + 1;

    for (;j < statements_.size(); j++) {

        if ((statements_[j]->get_type() == Stmt::Stmt_Type::BORROW || 
             statements_[j]->get_type() == Stmt::Stmt_Type::ALLOC)) {
            
            if (std::get<Stmt::Stmt_Borrow>(statements_[j] -> get_stmt()).register_ -> get_name() == name)
                layer++;

        }
        if (statements_[j]->get_type() == Stmt::Stmt_Type::REL &&
            std::get<Stmt::Stmt_Rel>(statements_[j] -> get_stmt()).id_ == name) {

            if (layer == 0) break;
            layer--;

        }
    }


    const auto& sub_program = make_program(
        std::vector<std::shared_ptr<Stmt> >(statements_.begin() + i + 1, statements_.begin() + j)
    );

    if (sub_program -> rename_borrow_alloc())  {

        for (size_t k = i + 1; k < j; k++) {
            statements_[k] = sub_program -> statements_[k - i - 1];
        }
        name_idx += sub_program -> name_idx;
        return true;

    }

    statements_[i] = statements_[i] -> substitute_reg(name, "__q" + std::to_string(++name_idx));
    statements_[j] = statements_[j] -> substitute_reg(name, "__q" + std::to_string(name_idx));
    
    for (size_t k = i + 1; k < j; k++) {

        statements_[k] = statements_[k] -> substitute_reg(name, "__q" + std::to_string(name_idx));
    
    }

    return true;
}


bool Program::free_name_check() const {
    for (const auto& stmt : statements_) {
        switch (stmt->get_type()) {
            case Stmt::Stmt_Type::BORROW: {
                if (std::get<Stmt::Stmt_Borrow>(stmt -> get_stmt()).register_ -> get_name()[0] != '_') {
                    return false; // found a register name that does not start with '_'
                }
                break;
            }
            case Stmt::Stmt_Type::ALLOC: {
                if (std::get<Stmt::Stmt_Alloc>(stmt -> get_stmt()).register_ -> get_name()[0] != '_') {
                    return false; // found a register name that does not start with '_'
                }
                break;
            }
            case Stmt::Stmt_Type::REL: {
                if (std::get<Stmt::Stmt_Rel>(stmt -> get_stmt()).id_[0] != '_') {
                    return false; // found a relation id that does not start with '_'
                }
                break;
            }
            case Stmt::Stmt_Type::X: {
                if (std::get<Stmt::Stmt_X>(stmt->get_stmt()).target_ -> get_name()[0] != '_') {
                    return false; // found a target register name that does not start with '_'
                }
                break;
            }
            case Stmt::Stmt_Type::CNOT: {
                const auto& tmp = stmt -> get_stmt();
                const auto& cnot_stmt = std::get<Stmt::Stmt_CNOT>(tmp);
                if (cnot_stmt.control_ -> get_name()[0] != '_' ||
                    cnot_stmt.target_ -> get_name()[0] != '_') {
                    return false; // found a control or target register name that does not start with '_'
                }
                break;
            }   
            case Stmt::Stmt_Type::CCNOT: {
                const auto& tmp = stmt -> get_stmt();
                const auto& ccnot_stmt = std::get<Stmt::Stmt_CCNOT>(tmp);
                if (ccnot_stmt.control1_ -> get_name()[0] != '_' ||
                    ccnot_stmt.control2_ -> get_name()[0] != '_' ||
                    ccnot_stmt.target_ -> get_name()[0] != '_') {
                    return false; // found a control or target register name that does not start with '_'
                }
                break;
            }
            case Stmt::Stmt_Type::FOR: {
                const auto& tmp = stmt -> get_stmt();
                const auto& for_stmt = std::get<Stmt::Stmt_For>(tmp);
                if (!make_program(for_stmt.body_) -> free_name_check()) {
                    return false; // check body statements recursively
                }
                break;
            }
            default: 
                break; // other statement types do not have register names to check
        }
    }
    return true; // all registers have names starting with '_'
}