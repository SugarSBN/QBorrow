
#include "AST_Function.h"

/*
    Constructor
*/
Function::Function(const std::string& name, 
                   const std::vector<std::string>& params, 
                   const std::vector<std::shared_ptr<Register> >& registers,
                   const std::vector<std::shared_ptr<Stmt> >& body)
    : name_(name), params_(params), registers_(registers), body_(body) {}


/*
    function factory method
*/
std::shared_ptr<Function> Function::make_function(const std::string& name, 
                                            const std::vector<std::string>& params, 
                                            const std::vector<std::shared_ptr<Register> >& registers,
                                            const std::vector<std::shared_ptr<Stmt> >& body) {
    return std::make_shared<Function>(Function(name, params, registers, body));
}

std::string Function::get_name() const {
    return name_;
}

std::vector<std::string> Function::get_params() const {
    return params_;
}

std::vector<std::shared_ptr<Register> > Function::get_registers() const {
    return registers_;
}

std::vector<std::shared_ptr<Stmt> > Function::get_body() const {
    return body_;
}


/*
    pretty print functions
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Function::print_function(std::ostream& os) const {
    os << BLUE << "function " << RESET << name_ << "(";
    for (size_t i = 0; i < params_.size(); i++) {
        os << params_[i];
        if (i < params_.size() - 1) {
            os << ", ";
        }
    }
    os << ") [";

    for (const auto& reg : registers_) {
        reg -> print_register(os);
        os << ",  ";
    }

    os << "] {";

    for (const auto& stmt : body_) {
        os << std::endl;
        stmt -> print_stmt(os, 1);
    }

    os << std::endl << "}";
}