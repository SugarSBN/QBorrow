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
    static std :: shared_ptr<Expr> make_variable(const std :: string& name);
    static std :: shared_ptr<Expr> make_number(int value);
    static std :: shared_ptr<Expr> make_unary_op(Unary_Op op, std :: shared_ptr<Expr> operand);
    static std :: shared_ptr<Expr> make_binary_op(Binary_Op op,
                                                std :: shared_ptr<Expr> left,
                                                std :: shared_ptr<Expr> right);

    static void print_expr(const Expr& expr, std :: ostream& os = std :: cout); 
};








class Stmt {
    
public:
    enum class Stmt_Type {
        LET,
        BORROW, 
        // ALLOC, 
        // X, 
        // CNOT, 
        // CCNOT
    };


    struct Stmt_Let {
        std :: string id_;
        std :: shared_ptr<Expr> expr_;
    };

    struct Stmt_Borrow {
        std :: string id_;
        bool is_register_;
        std :: shared_ptr<Expr> expr_;
    };


    // constructors
    explicit Stmt (Stmt_Type t, const std :: string& name, std :: shared_ptr<Expr> expr)
        : stmt_(Stmt_Let{name, expr}), type_(t) {}
    
    explicit Stmt (Stmt_Type t, const std :: string& name, bool is_register, std :: shared_ptr<Expr> expr)
        : stmt_(Stmt_Borrow{name, is_register, expr}), type_(t) {}

        
    // factory methods for creating pointers to statements
    static std :: shared_ptr<Stmt> make_let(const std :: string& name, std :: shared_ptr<Expr> expr);
    static std :: shared_ptr<Stmt> make_borrow(const std :: string& name, bool is_register, std :: shared_ptr<Expr> expr);
    

    // interfaces to obtain the statement type and its content
    std :: variant<
       Stmt_Let,
       Stmt_Borrow
    > get_stmt() const;


    Stmt get_type() const;

    void print_stmt(std :: ostream& os = std :: cout) const;

private:
    std :: variant<
       Stmt_Let,
       Stmt_Borrow
    > stmt_;

    Stmt_Type type_;

};