
#include "AST_Register.h"


/*
    Constructors
*/
Register::Register(const std::string& name, const std::shared_ptr<Expr>& size)
    : name_(name), size_(size) {}

/*
    register factory method
*/
std::shared_ptr<Register> Register::make_register(const std::string& name, const std::shared_ptr<Expr>& size) {
    return std::make_shared<Register>(Register(name, size));
}

/*
    pretty print registers
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Register::print_register(std::ostream& os) const {
    os << name_;
    if (size_ != nullptr) {
        os << "["; 
        size_ -> print_expr(os);
        os << "]";
    }
}

std::shared_ptr<Register> Register::substitute(const std::string& name, const std::shared_ptr<Expr>& value) const {
    return Register::make_register(name_, size_ ? size_ -> substitute(name, value) : nullptr);
}

std::shared_ptr<Register> Register::evaluate() const {
    if (size_ == nullptr) {
        return Register::make_register(name_, nullptr);
    }
    return Register::make_register(name_, Expr::make_number(size_ -> evaluate()));
}

std::string Register::get_name() const {
    return name_;
}

void Register::set_name(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Expr> Register::get_size() const {
    return size_;
}