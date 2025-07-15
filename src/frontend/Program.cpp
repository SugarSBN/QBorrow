
#include "Program.h"

std::shared_ptr<Program> Program::make_program(const std::vector<std::shared_ptr<Function> >& functions,
                                               const std::vector<std::shared_ptr<Stmt> >& statements) {
    return std::make_shared<Program>(Program(functions, statements));
}

Program::Program(const std::vector<std::shared_ptr<Function> >& functions,
                 const std::vector<std::shared_ptr<Stmt> >& statements)
    : functions_(functions), statements_(statements) {}

void Program::print_program(std::ostream& os) const {
    for (const auto& func : functions_) {
        func->print_function(os);
        os << std::endl;
    }
    for (const auto& stmt : statements_) {
        stmt->print_stmt(os);
        os << std::endl;
    }
}

std::vector<std::shared_ptr<Function> > Program::get_functions() const {
    return functions_;
}

std::vector<std::shared_ptr<Stmt> > Program::get_statements() const {
    return statements_;
}

bool Program::eliminate_let_statements() {

    for (const auto& func : functions_) {
        const auto& body_program = make_program(std::vector<std::shared_ptr<Function> >(), func -> get_body());
        if (body_program -> eliminate_let_statements()) {
            func -> set_body(body_program -> get_statements());
            return true;
        }
    }

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

    for (const auto& func : functions_) {
        const auto& body_program = make_program(std::vector<std::shared_ptr<Function> >(), func -> get_body());
        if (body_program -> eliminate_for_statements()) {
            func -> set_body(body_program -> get_statements());
            return true;
        }
    }

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