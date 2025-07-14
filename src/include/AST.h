// AST 节点结构
#pragma once 
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <variant>

struct Expr {

    // type definitions
    enum class Expr_Type {
        ID,
        NUMBER,
        UnaryOp,
        BinaryOp
    };

    enum class Unary_Op {
        NEGATE
    };

    enum class Binary_Op {
        ADD,
        MUL,
        SUB
    };


    // expressions
    struct Expr_ID {
        std :: string id;
    };

    struct Expr_Number {
        int number;  
    };

    struct Expr_Unary_Op {
        Unary_Op op;
        std :: shared_ptr<Expr> operand;
    };

    struct Expr_Binary_Op {
        Binary_Op op;
        std :: shared_ptr<Expr> left;
        std :: shared_ptr<Expr> right;
    };


    // an expression is type + contents
    Expr_Type type_;

    std :: variant<
        Expr_ID,
        Expr_Number,
        Expr_Unary_Op,
        Expr_Binary_Op
    > expr_;

    // constructors
    Expr(Expr_Type t, const std :: string& name)
        : type_(t), expr_(Expr_ID{name}) {}

    Expr(Expr_Type t, int value)
        : type_(t), expr_(Expr_Number{value}) {}

    Expr(Expr_Type t, Unary_Op op, std :: shared_ptr<Expr> operand)
        : type_(t), expr_(Expr_Unary_Op{op, std :: move(operand)}) {}

    Expr(Expr_Type t, Binary_Op op,
         std :: shared_ptr<Expr> left,
         std :: shared_ptr<Expr> right)
        : type_(t), expr_(Expr_Binary_Op{op, std :: move(left), std :: move(right)}) {}

    
    // factory methods for creating pointers to expressions
    static std :: shared_ptr<Expr> make_variable(const std :: string& name) {
        return std :: make_shared<Expr>(Expr_Type :: ID, name);
    }

    static std :: shared_ptr<Expr> make_number(int value) {
        return std :: make_shared<Expr>(Expr_Type :: NUMBER, value);
    }

    static std :: shared_ptr<Expr> make_unary_op(Unary_Op op, std :: shared_ptr<Expr> operand) {
        return std :: make_shared<Expr>(Expr_Type :: UnaryOp, op, std :: move(operand));
    }

    static std :: shared_ptr<Expr> make_binary_op(Binary_Op op,
                                                std :: shared_ptr<Expr> left,
                                                std :: shared_ptr<Expr> right) {
        return std :: make_shared<Expr>(Expr_Type :: BinaryOp, op, std :: move(left), std :: move(right));
    }

    static void print_expr(const Expr& expr, std :: ostream& os = std :: cout) {
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
                    case Binary_Op :: ADD: os << "+"; break;
                    case Binary_Op :: MUL: os << "*"; break;
                    case Binary_Op :: SUB: os << "-"; break;
                }
                print_expr(*binary.right, os);
                os << ")";
                break;
            }
        }
    }
};








class Stmt {
    
public:
    enum class Stmt_Type {
        LET, 
        // BORROW, 
        // ALLOC, 
        // X, 
        // CNOT, 
        // CCNOT
    };


    struct Stmt_Let {
        std :: string id_;
        Expr expr_;
    };

    // constructor for let
    explicit Stmt (Stmt_Type t, const std :: string& name, std :: shared_ptr<Expr> expr);
    
    

    // interfaces to obtain the statement type and its content
    std :: variant<
       Stmt_Let
    > get_stmt() const;


    Stmt get_type() const;

    void print_stmt(std :: ostream& os = std :: cout) const {
        switch (type_) {
            case Stmt_Type :: LET :  
                const auto& let_stmt = std :: get<Stmt_Let>(stmt_);
                os << "let " << let_stmt.id_ << " = ";
                Expr :: print_expr(let_stmt.expr_, os);
                os << ";";
                break;
            
            // case Stmt_Type :: BORROW: 
            //     // handle borrow statement
            //     break;
            // case Stmt_Type :: ALLOC: 
            //     // handle alloc statement
            //     break;
        }
    }

private:
    std :: variant<
       Stmt_Let
    > stmt_;

    Stmt_Type type_;

};