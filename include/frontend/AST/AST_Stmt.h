
#pragma once 
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <variant>

#include "AST_Expr.h"
#include "AST_Register.h"

class Stmt {
    
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
        FOR,
        CALL
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

    struct Stmt_Rel {
        std :: string id_;
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

    struct Stmt_Call {
        std :: string function_name_;
        std :: vector<std :: shared_ptr<Expr> > args_;
        std :: vector<std :: shared_ptr<Register> > regs_;
    };


    /*
        constructors
    */
    explicit Stmt (Stmt_Type t, std :: variant<
        Stmt_Let,
        Stmt_Borrow,
        Stmt_Alloc,
        Stmt_Rel,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For,
        Stmt_Call
    > stmt)
        : stmt_(std::move(stmt)), type_(t) {}
        
    explicit Stmt (Stmt_Type t, const std :: string& name, std :: shared_ptr<Expr> expr)
        : stmt_(Stmt_Let{name, expr}), type_(t) {}
    
    explicit Stmt (Stmt_Type t, const std :: string& name)
        : stmt_(Stmt_Rel{name}), type_(t) {}

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

    explicit Stmt (Stmt_Type t, const std :: string& function_name, 
                   const std :: vector<std :: shared_ptr<Expr> >& args,
                   const std :: vector<std :: shared_ptr<Register> >& regs)
        : stmt_(Stmt_Call{function_name, args, regs}), type_(t) {}

    /*
        factory methods for creating pointers to statements
    */ 
    static std :: shared_ptr<Stmt> make_stmt(Stmt_Type type, 
                                              std :: variant<
                                                  Stmt_Let,
                                                  Stmt_Borrow,
                                                  Stmt_Alloc,
                                                  Stmt_Rel,
                                                  Stmt_X,
                                                  Stmt_CNOT,
                                                  Stmt_CCNOT,
                                                  Stmt_For,
                                                  Stmt_Call
                                              > stmt);
    static std :: shared_ptr<Stmt> make_let(const std :: string& name, std :: shared_ptr<Expr> expr);
    static std :: shared_ptr<Stmt> make_borrow(std :: shared_ptr<Register> reg);
    static std :: shared_ptr<Stmt> make_alloc(std :: shared_ptr<Register> reg);
    static std :: shared_ptr<Stmt> make_rel(const std :: string& id);
    static std :: shared_ptr<Stmt> make_x(std :: shared_ptr<Register> target);
    static std :: shared_ptr<Stmt> make_cnot(std :: shared_ptr<Register> control, std :: shared_ptr<Register> target);
    static std :: shared_ptr<Stmt> make_ccnot(std :: shared_ptr<Register> control1, 
                                              std :: shared_ptr<Register> control2, 
                                              std :: shared_ptr<Register> target);
    static std :: shared_ptr<Stmt> make_for(const std :: string& id, 
                                            std :: shared_ptr<Expr> start, 
                                            std :: shared_ptr<Expr> end, 
                                            std :: vector<std :: shared_ptr<Stmt>> body);
    static std :: shared_ptr<Stmt> make_call(const std :: string& function_name, 
                                             const std :: vector<std :: shared_ptr<Expr> >& args,
                                             const std :: vector<std :: shared_ptr<Register> >& regs);
    
    std :: shared_ptr<Stmt> substitute(const std :: string& name, std :: shared_ptr<Expr> value) const;
                                        
    /*
        interfaces to obtain the statement type and its content
    */ 
    std :: variant<
        Stmt_Let,
        Stmt_Borrow,
        Stmt_Alloc,
        Stmt_Rel,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For,
        Stmt_Call
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
        Stmt_Rel,
        Stmt_X,
        Stmt_CNOT,
        Stmt_CCNOT,
        Stmt_For,
        Stmt_Call
    > stmt_;

    Stmt_Type type_;

};





