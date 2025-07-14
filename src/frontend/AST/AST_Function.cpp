
#include "AST_Function.h"

/*
    function factory method
*/
std :: shared_ptr<Function> Function :: make_function(const std :: string& name, 
                                            const std :: vector<std :: string>& params, 
                                            const std :: vector<std :: shared_ptr<Register> >& registers,
                                            const std :: vector<std :: shared_ptr<Stmt> >& body) {
    return std :: make_shared<Function>(name, params, registers, body);
}


/*
    pretty print functions
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Function :: print_function(std :: ostream& os) const {
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
        os << std :: endl;
        stmt -> print_stmt(os, 1);
    }

    os << std :: endl << "}";
}