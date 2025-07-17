
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

std::shared_ptr<Register> Register::clone() const {
    return make_register(name_, size_ -> clone());
}

/*
    pretty print registers
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Register::print(std::ostream& os) const {
    os << name_;
    if (size_ != nullptr) {
        os << "["; 
        size_ -> print(os);
        os << "]";
    }
}


void Register::substitute(const std::string& name, const std::shared_ptr<Expr>& value) {
    if (size_ != nullptr) size_ -> substitute(name, value);
}

void Register::evaluate(){
    if (size_ != nullptr) size_ -> evaluate();
}

const std::string& Register::get_name() const {
    return name_;
}

void Register::set_name(const std::string& name) {
    name_ = name;
}

const std::shared_ptr<Expr>& Register::get_size() const {
    return size_;
}