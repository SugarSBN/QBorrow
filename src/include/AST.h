// AST 节点结构
#pragma once 
#include <string>
#include <vector>
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



struct Register {
    std :: string name_;
    std :: shared_ptr<Expr> size_;

    static std :: shared_ptr<Register> make_register(const std :: string& name, std :: shared_ptr<Expr> size);

    void print_register(std :: ostream& os = std :: cout) const;
};







class Stmt {
    
public:
    /*
        statement types
    */
    enum class Stmt_Type {
        LET,
        BORROW, 
        ALLOC,
        X, 
        CNOT, 
        CCNOT,
        FOR
    };


    /*
        specific statements
    */
    struct Stmt_Let {
        std :: string id_;
        std :: shared_ptr<Expr> expr_;
    };

    struct Stmt_Borrow {
        std :: shared_ptr<Register> register_;
    };

    struct Stmt_Alloc {
        std :: shared_ptr<Register> register_;
    };

    struct Stmt_X {
        std :: shared_ptr<Register> target_;
    };

    struct Stmt_CNOT {
        std :: shared_ptr<Register> control_;
        std :: shared_ptr<Register> target_;
    };

    struct Stmt_CCNOT {
        std :: shared_ptr<Register> control1_;
        std :: shared_ptr<Register> control2_;
        std :: shared_ptr<Register> target_;
    };

    struct Stmt_For {
        std :: string id_;
        std :: shared_ptr<Expr> start_;
        std :: shared_ptr<Expr> end_;
        std :: vector<std :: shared_ptr<Stmt> > body_;
    };

    /*
        constructors
    */
    explicit Stmt (Stmt_Type t, const std :: string& name, std :: shared_ptr<Expr> expr)
        : stmt_(Stmt_Let{name, expr}), type_(t) {}
    
    explicit Stmt (Stmt_Type t, std :: shared_ptr<Register> reg)
        : type_(t) {
            switch (t) {

            case Stmt_Type :: BORROW:  stmt_ = Stmt_Borrow{reg}; break; 
            case Stmt_Type :: ALLOC:   stmt_ = Stmt_Alloc{reg}; break; 
            case Stmt_Type :: X:       stmt_ = Stmt_X{reg}; break;

            default:
                throw std::runtime_error("Unsupported statement type for this constructor.");
           
        }
    }

    explicit Stmt (Stmt_Type t, std :: shared_ptr<Register> control, std :: shared_ptr<Register> target)
        : stmt_(Stmt_CNOT{control, target}), type_(t) {}
    
    explicit Stmt (Stmt_Type t, std :: shared_ptr<Register> control1, std :: shared_ptr<Register> control2, std :: shared_ptr<Register> target)
        : stmt_(Stmt_CCNOT{control1, control2, target}), type_(t) {}

    explicit Stmt (Stmt_Type t, const std :: string& id, std :: shared_ptr<Expr> start, std :: shared_ptr<Expr> end, std :: vector<std :: shared_ptr<Stmt>> body)
        : stmt_(Stmt_For{id, start, end, std::move(body)}), type_(t) {}


    /*
        factory methods for creating pointers to statements
    */ 
    static std :: shared_ptr<Stmt> make_let(const std :: string& name, std :: shared_ptr<Expr> expr);
    static std :: shared_ptr<Stmt> make_borrow(std :: shared_ptr<Register> reg);
    static std :: shared_ptr<Stmt> make_alloc(std :: shared_ptr<Register> reg);
    static std :: shared_ptr<Stmt> make_x(std :: shared_ptr<Register> target);
    static std :: shared_ptr<Stmt> make_cnot(std :: shared_ptr<Register> control, std :: shared_ptr<Register> target);
    static std :: shared_ptr<Stmt> make_ccnot(std :: shared_ptr<Register> control1, 
                                              std :: shared_ptr<Register> control2, 
                                              std :: shared_ptr<Register> target);
    static std :: shared_ptr<Stmt> make_for(const std :: string& id, 
                                            std :: shared_ptr<Expr> start, 
                                            std :: shared_ptr<Expr> end, 
                                            std :: vector<std :: shared_ptr<Stmt>> body);

    /*
        interfaces to obtain the statement type and its content
    */ 
    std :: variant<
        Stmt_Let,
        Stmt_Borrow,
        Stmt_Alloc,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For
    > get_stmt() const;

    Stmt_Type get_type() const;

    /*
        pretty print statements
    */
    void print_stmt(std :: ostream& os = std :: cout, int layer = 0) const;

private:

    /*
        a statement is a type + variant.
    */
    std :: variant<
        Stmt_Let,
        Stmt_Borrow,
        Stmt_Alloc,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For
    > stmt_;

    Stmt_Type type_;

};