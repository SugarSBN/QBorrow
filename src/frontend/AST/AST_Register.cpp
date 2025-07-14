
#include "AST_Register.h"


/*
    register factory method
*/
std :: shared_ptr<Register> Register :: make_register(const std :: string& name, std :: shared_ptr<Expr> size) {
    return std :: make_shared<Register>(Register{
        name, 
        std :: move(size)
    });
}

/*
    pretty print registers
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Register :: print_register(std :: ostream& os) const {
    os << name_;
    if (size_ != nullptr) {
        os << "["; 
        size_ -> print_expr(os);
        os << "]";
    }
}

std :: shared_ptr<Register> Register :: substitute(const std :: string& name, std :: shared_ptr<Expr> value) const {
    return Register::make_register(name_, size_ ? size_ -> substitute(name, value) : nullptr);
}