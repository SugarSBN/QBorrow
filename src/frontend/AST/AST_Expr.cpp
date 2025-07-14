
#include "AST_Expr.h"

// Expr factory methods

std :: shared_ptr<Expr> Expr :: make_variable(const std :: string& name) { 
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: ID,
        Expr_ID{name}
    });
}


std :: shared_ptr<Expr> Expr :: make_number(int value) {
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: NUMBER,
        Expr_Number{value}
    });
}


std :: shared_ptr<Expr> Expr :: make_unary_op(Unary_Op op, std :: shared_ptr<Expr> operand) {
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: UnaryOp,
        Expr_Unary_Op{op, std :: move(operand)}
    });
}


std :: shared_ptr<Expr> Expr :: make_binary_op(Binary_Op op,
                                                std :: shared_ptr<Expr> left,
                                                std :: shared_ptr<Expr> right) {
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: BinaryOp,
        Expr_Binary_Op{op, std :: move(left), std :: move(right)}
    });
}

/*
        pretty print expressions
*/
#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Expr :: print_expr(std :: ostream& os) const {
    switch (type_) {
        case Expr_Type :: ID:
            os << std :: get<Expr_ID>(expr_).id_;
            break;
        case Expr_Type :: NUMBER:
            os << std :: get<Expr_Number>(expr_).number_;
            break;
        case Expr_Type :: UnaryOp: {
            const auto& unary = std :: get<Expr_Unary_Op>(expr_);

            switch (unary.op_) {
                case Unary_Op :: NEGATE: os << "-"; break;
            }

            os << "(";
            unary.operand_ -> print_expr(os);
            os << ")";
            break;
        }
        case Expr_Type :: BinaryOp: {
            const auto& binary = std :: get<Expr_Binary_Op>(expr_);

            os << "(";
            binary.left_ -> print_expr(os);

            switch (binary.op_) {
                case Binary_Op :: ADD: os << RED << "+" << RESET; break;
                case Binary_Op :: MUL: os << RED << "*" << RESET; break;
                case Binary_Op :: SUB: os << RED << "-" << RESET; break;
            }
            binary.right_ -> print_expr(os);
            os << ")";
            break;
        }
    }
}



std :: shared_ptr<Expr> Expr :: substitute(const std :: string& name, std :: shared_ptr<Expr> value) const {
    switch (type_) {
        case Expr_Type :: ID: {
            const auto& id_expr = std :: get<Expr_ID>(expr_);

            if (id_expr.id_ == name) {
                return value;
            }

            return make_variable(id_expr.id_);
        }
        case Expr_Type :: NUMBER: {
            const auto& number_expr = std :: get<Expr_Number>(expr_);
            return make_number(number_expr.number_);
        }
        case Expr_Type :: UnaryOp: {
            const auto& unary_expr = std :: get<Expr_Unary_Op>(expr_);
            return make_unary_op(unary_expr.op_, unary_expr.operand_ -> substitute(name, value));
        }
        case Expr_Type :: BinaryOp: {
            const auto& binary_expr = std :: get<Expr_Binary_Op>(expr_);
            return make_binary_op(binary_expr.op_,
                                  binary_expr.left_ -> substitute(name, value),
                                  binary_expr.right_ -> substitute(name, value));
        }
    }
}