
#pragma once 
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <variant>

#include "AST_Expr.h"
#include "AST_Register.h"

class Stmt final : public Printable, public Substitutable, public Evaluatable {
    
public:
    /*
        statement types
    */
    enum class Stmt_Type {
        LET,
        BORROW, 
        ALLOC,
        REL,
        X, 
        CNOT, 
        CCNOT,
        FOR
    };


    /*
        specific statements
    */
    struct Stmt_Let {
        std::string id_;
        std::shared_ptr<Expr> expr_;
    };

    struct Stmt_Borrow {
        std::shared_ptr<Register> register_;
        bool need_check_;
    };

    struct Stmt_Alloc {
        std::shared_ptr<Register> register_;
    };

    struct Stmt_Rel {
        std::string id_;
    };

    struct Stmt_X {
        std::shared_ptr<Register> target_;
    };

    struct Stmt_CNOT {
        std::shared_ptr<Register> control_;
        std::shared_ptr<Register> target_;
    };

    struct Stmt_CCNOT {
        std::shared_ptr<Register> control1_;
        std::shared_ptr<Register> control2_;
        std::shared_ptr<Register> target_;
    };

    struct Stmt_For {
        std::string id_;
        std::shared_ptr<Expr> start_;
        std::shared_ptr<Expr> end_;
        std::vector<std::shared_ptr<Stmt> > body_;
    };



    /*
        factory methods for creating pointers to statements
    */ 
    static std::shared_ptr<Stmt> make_let     (const std::string& name, const std::shared_ptr<Expr>& expr, const int& lineno);
    static std::shared_ptr<Stmt> make_borrow  (const std::shared_ptr<Register>& reg, const bool& need_check, const int& lineno);
    static std::shared_ptr<Stmt> make_alloc   (const std::shared_ptr<Register>& reg, const int& lineno);
    static std::shared_ptr<Stmt> make_rel     (const std::string& id, const int& lineno);
    static std::shared_ptr<Stmt> make_x       (const std::shared_ptr<Register>& target, const int& lineno);
    static std::shared_ptr<Stmt> make_cnot    (const std::shared_ptr<Register>& control, 
                                               const std::shared_ptr<Register>& target, 
                                               const int& lineno);
    static std::shared_ptr<Stmt> make_ccnot   (const std::shared_ptr<Register>& control1, 
                                               const std::shared_ptr<Register>& control2, 
                                               const std::shared_ptr<Register>& target,
                                               const int& lineno);
    static std::shared_ptr<Stmt> make_for     (const std::string& id, 
                                               const std::shared_ptr<Expr>& start, 
                                               const std::shared_ptr<Expr>& end, 
                                               const std::vector<std::shared_ptr<Stmt> >& body,
                                               const int& lineno);
    


    /*        
        substitute the statement with a new expression
        this is used for variable substitution in the preprocessor
    */
    void substitute(const std::string& name, const std::shared_ptr<Expr>& value) override;
    void evaluate() override;
    void print(std::ostream& os) const override;

    void substitute_reg(const std::string& name, const std::string& value);
    
    /*
        interfaces to obtain the statement type and its content
    */ 
    const std::variant<
        Stmt_Let,
        Stmt_Borrow,
        Stmt_Alloc,
        Stmt_Rel,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For
    >& get_stmt() const;
    const Stmt_Type& get_type() const;
    const int& get_lineno() const;

    std::shared_ptr<Stmt> clone() const;
    
private:
    
/*
        constructors
    */        
    explicit Stmt (Stmt_Type t, const std::string& name, const std::shared_ptr<Expr>& expr, const int& lineno);
    explicit Stmt (Stmt_Type t, const std::string& name, const int& lineno);
    explicit Stmt (Stmt_Type t, const std::shared_ptr<Register>& reg, const int& lineno);
    explicit Stmt (Stmt_Type t, const std::shared_ptr<Register>& reg, const bool& need_check, const int& lineno);
    explicit Stmt (Stmt_Type t, const std::shared_ptr<Register>& control, const std::shared_ptr<Register>& target, const int& lineno);
    explicit Stmt (Stmt_Type t, 
                   const std::shared_ptr<Register>& control1, 
                   const std::shared_ptr<Register>& control2, 
                   const std::shared_ptr<Register>& target,
                   const int& lineno);
    explicit Stmt (Stmt_Type t, 
                   const std::string& id, 
                   const std::shared_ptr<Expr>& start, 
                   const std::shared_ptr<Expr>& end, 
                   const std::vector<std::shared_ptr<Stmt> >& body,
                   const int& lineno);

    void print_stmt(std::ostream& os, const int& layer = 0) const;
   

    /*
        a statement is a type + variant.
    */
    std::variant<
        Stmt_Let,
        Stmt_Borrow,
        Stmt_Alloc,
        Stmt_Rel,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For
    > stmt_;

    Stmt_Type type_;

    int lineno_;
};





