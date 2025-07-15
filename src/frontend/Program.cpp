
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

