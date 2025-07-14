
#include "AST.h"
#include <string>





// Expr factory methods

std :: shared_ptr<Expr> Expr :: make_variable(const std :: string& name) {
        return std :: make_shared<Expr>(Expr_Type :: ID, name);
}


std :: shared_ptr<Expr> Expr :: make_number(int value) {
        return std :: make_shared<Expr>(Expr_Type :: NUMBER, value);
}


std :: shared_ptr<Expr> Expr :: make_unary_op(Unary_Op op, std :: shared_ptr<Expr> operand) {
        return std :: make_shared<Expr>(Expr_Type :: UnaryOp, op, std :: move(operand));
}


std :: shared_ptr<Expr> Expr :: make_binary_op(Binary_Op op,
                                                std :: shared_ptr<Expr> left,
                                                std :: shared_ptr<Expr> right) {
        return std :: make_shared<Expr>(Expr_Type :: BinaryOp, op, std :: move(left), std :: move(right));
}







// Stmt factory methods

std :: shared_ptr<Stmt> Stmt :: make_let(const std :: string& name, std :: shared_ptr<Expr> expr){
        return std :: make_shared<Stmt>(Stmt_Type :: LET, name, std :: move(expr));
}

std :: shared_ptr<Stmt> Stmt :: make_borrow(const std :: string& name, bool is_register, std :: shared_ptr<Expr> expr) {
        return std :: make_shared<Stmt>(Stmt_Type :: BORROW, name, is_register, std :: move(expr));
}



Stmt :: Stmt_Type Stmt :: get_type() const {
    return type_;
}


/*
        pretty print expressions
*/
#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Expr :: print_expr(const Expr& expr, std :: ostream& os) {
        switch (expr.type_) {
            case Expr_Type :: ID:
                os << std :: get<Expr_ID>(expr.expr_).id;
                break;
            case Expr_Type :: NUMBER:
                os << std :: get<Expr_Number>(expr.expr_).number;
                break;
            case Expr_Type :: UnaryOp: {
                const auto& unary = std :: get<Expr_Unary_Op>(expr.expr_);

                switch (unary.op) {
                    case Unary_Op :: NEGATE: os << "-"; break;
                }

                os << "(";
                print_expr(*unary.operand, os);
                os << ")";
                break;
            }
            case Expr_Type :: BinaryOp: {
                const auto& binary = std :: get<Expr_Binary_Op>(expr.expr_);

                os << "(";
                print_expr(*binary.left, os);

                switch (binary.op) {
                    case Binary_Op :: ADD: os << RED << "+" << RESET; break;
                    case Binary_Op :: MUL: os << RED << "*" << RESET; break;
                    case Binary_Op :: SUB: os << RED << "-" << RESET; break;
                }
                print_expr(*binary.right, os);
                os << ")";
                break;
            }
        }
    }

void Stmt :: print_stmt(std :: ostream& os) const {
        switch (type_) {
            case Stmt_Type :: LET : { 
                const auto& let_stmt = std :: get<Stmt_Let>(stmt_);
                os << BLUE << "let " << RESET << let_stmt.id_ << RED << " = " << RESET;
                Expr :: print_expr(*let_stmt.expr_, os);
                os << ";";
                break;
            }
            case Stmt_Type :: BORROW : {
                const auto& borrow_stmt = std :: get<Stmt_Borrow>(stmt_);
                os << BLUE << "borrow " << RESET << borrow_stmt.id_;
                if (borrow_stmt.is_register_) {
                    os << "["; 
                    Expr :: print_expr(*borrow_stmt.expr_, os);
                    os << "]";
                }
                os << ";";
                break;
            }
        //     case Stmt_Type :: ALLOC: 
        //         // handle alloc statement
        //         break;
        }
}