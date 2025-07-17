
#include "AST_Expr.h"

/*
    Constructors
*/
Expr::Expr(const Expr_Type& t, const std::string& name) 
    : type_(t), expr_(Expr_ID{name}) {}
Expr::Expr(const Expr_Type& t, const int& number) 
    : type_(t), expr_(Expr_Number{number}) {}
Expr::Expr(const Expr_Type& t, const Unary_Op& op, const std::shared_ptr<Expr>& operand) 
    : type_(t), expr_(Expr_Unary_Op{op, operand}) {}
Expr::Expr(const Expr_Type& t, const Binary_Op& op, const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) 
    : type_(t), expr_(Expr_Binary_Op{op, left, right}) {}



/*
    factory methods 
*/

std::shared_ptr<Expr> Expr::make_variable(const std::string& name) { 
    return std::make_shared<Expr>(Expr(
        Expr_Type::ID,
        name
    ));
}


std::shared_ptr<Expr> Expr::make_number(const int& value) {
    return std::make_shared<Expr>(Expr(
        Expr_Type::NUMBER,
        value
    ));
}


std::shared_ptr<Expr> Expr::make_unary_op(const Unary_Op& op, const std::shared_ptr<Expr>& operand) {
    return std::make_shared<Expr>(Expr(
        Expr_Type::UnaryOp,
        op,
        operand
    ));
}


std::shared_ptr<Expr> Expr::make_binary_op(const Binary_Op& op, const std::shared_ptr<Expr>& left, const std::shared_ptr<Expr>& right) {
    return std::make_shared<Expr>(Expr(
        Expr_Type::BinaryOp,
        op,
        left,
        right
    ));
}

const int& Expr::get_number() const {
    return std::get<Expr_Number>(expr_).number_;
}

std::shared_ptr<Expr> Expr::clone() const {
    switch (type_) {
        case Expr_Type::ID:
            return std::make_shared<Expr>(Expr(*this));
        case Expr_Type::NUMBER:
            return std::make_shared<Expr>(Expr(*this));
        case Expr_Type::UnaryOp: {
            const auto& unary = std::get<Expr_Unary_Op>(expr_);
            return make_unary_op(unary.op_, unary.operand_ -> clone());
        }
        case Expr_Type::BinaryOp: {
            const auto& binary = std::get<Expr_Binary_Op>(expr_);
            return make_binary_op(binary.op_, binary.left_ -> clone(), binary.right_ -> clone());
        }
    }
}

/*
        pretty print expressions
*/
#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Expr::print(std::ostream& os) const {
    switch (type_) {
        case Expr_Type::ID:
            os << std::get<Expr_ID>(expr_).id_;
            break;
        case Expr_Type::NUMBER:
            os << std::get<Expr_Number>(expr_).number_;
            break;
        case Expr_Type::UnaryOp: {
            const auto& unary = std::get<Expr_Unary_Op>(expr_);

            switch (unary.op_) {
                case Unary_Op::NEGATE: os << "-"; break;
            }

            os << "(";
            unary.operand_ -> print(os);
            os << ")";
            break;
        }
        case Expr_Type::BinaryOp: {
            const auto& binary = std::get<Expr_Binary_Op>(expr_);

            os << "(";
            binary.left_ -> print(os);

            switch (binary.op_) {
                case Binary_Op::ADD: os << RED << "+" << RESET; break;
                case Binary_Op::MUL: os << RED << "*" << RESET; break;
                case Binary_Op::SUB: os << RED << "-" << RESET; break;
            }
            binary.right_ -> print(os);
            os << ")";
            break;
        }
    }
}




void Expr::substitute(const std::string& name, const std::shared_ptr<Expr>& value) {
    switch (type_) {
        case Expr_Type::ID: {
            // std::cout<< "Substituting ID expression: " << std::get<Expr_ID>(expr_).id_ << " " << name << std::endl;
            // std::cout << (value -> type_ == Expr_Type::NUMBER) << std::endl;
            if (std::get<Expr_ID>(expr_).id_ == name) {
                type_ = value -> type_;
                expr_ = value -> clone() -> expr_;
            }
            // std::cout<< "Substituting ID expression: " << std::get<Expr_ID>(expr_).number_ << std::endl;
            break;
        }
        case Expr_Type::NUMBER:
            // No substitution needed for numbers
            break;
        case Expr_Type::UnaryOp: {
            auto& unary_expr = std::get<Expr_Unary_Op>(expr_);
            unary_expr.operand_ -> substitute(name, value);
            break;
        }
        case Expr_Type::BinaryOp: {
            auto& binary_expr = std::get<Expr_Binary_Op>(expr_);
            binary_expr.left_ -> substitute(name, value);
            binary_expr.right_ -> substitute(name, value);
            break;
        }
    }
}

void Expr::evaluate() {
    switch (type_) {
        case Expr_Type::ID: {
            throw std::runtime_error("Cannot evaluate an expression with variable: " + std::get<Expr_ID>(expr_).id_);
        }
        case Expr_Type::NUMBER: {
            break;
        }
        case Expr_Type::UnaryOp: {
            const auto& unary = std::get<Expr_Unary_Op>(expr_);
            unary.operand_ -> evaluate();
            int operand_value = std::get<Expr_Number>(unary.operand_ -> expr_).number_;

            type_ = Expr_Type::NUMBER;
            expr_ = Expr_Number{-operand_value}; // Negate the operand value
            break;
        }
        case Expr_Type::BinaryOp: {
            const auto& binary = std::get<Expr_Binary_Op>(expr_);
            binary.left_ -> evaluate();
            binary.right_ -> evaluate();

            int left_value = std::get<Expr_Number>(binary.left_ -> expr_).number_;
            int right_value = std::get<Expr_Number>(binary.right_ -> expr_).number_;

            int result;
            switch (binary.op_) {
                case Binary_Op::ADD: result = left_value + right_value; break;
                case Binary_Op::MUL: result = left_value * right_value; break;
                case Binary_Op::SUB: result = left_value - right_value; break;
            }

            type_ = Expr_Type::NUMBER;
            expr_ = Expr_Number{result};
            break;
        }
    }
}