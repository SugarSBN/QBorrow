
#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <variant>

struct Expr {

    /*
        expression types
        ID: variable name
        NUMBER: integer number
        UnaryOp: unary operator, e.g., -x
        BinaryOp: binary operator, e.g., x + y
    */
    enum class Expr_Type {
        ID,
        NUMBER,
        UnaryOp,
        BinaryOp
    };

    /*
        operator types
    */
    enum class Unary_Op {
        NEGATE
    };

    enum class Binary_Op {
        ADD,
        MUL,
        SUB
    };


    /*
        specific expressions
    */
    struct Expr_ID {
        std :: string id_;
    };

    struct Expr_Number {
        int number_;  
    };

    struct Expr_Unary_Op {
        Unary_Op op_;
        std :: shared_ptr<Expr> operand_;
    };

    struct Expr_Binary_Op {
        Binary_Op op_;
        std :: shared_ptr<Expr> left_;
        std :: shared_ptr<Expr> right_;
    };


    /*
        an expression is a type + variant.
    */
    Expr_Type type_;

    std :: variant<
        Expr_ID,
        Expr_Number,
        Expr_Unary_Op,
        Expr_Binary_Op
    > expr_;


    
    /*
        factory methods for creating pointers to expressions
    */ 
    static std :: shared_ptr<Expr> make_variable(const std :: string& name);
    static std :: shared_ptr<Expr> make_number(int value);
    static std :: shared_ptr<Expr> make_unary_op(Unary_Op op, std :: shared_ptr<Expr> operand);
    static std :: shared_ptr<Expr> make_binary_op(Binary_Op op,
                                                std :: shared_ptr<Expr> left,
                                                std :: shared_ptr<Expr> right);


    /*        
        pretty print expressions
    */
    void print_expr(std :: ostream& os = std :: cout) const;
};