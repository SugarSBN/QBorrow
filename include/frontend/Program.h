
#pragma once

#include "AST_Expr.h"
#include "AST_Register.h"
#include "AST_Stmt.h"


class Program {

public:
    
    /*
        factory method to create a program
    */
    static std::shared_ptr<Program> make_program(const std::vector<std::shared_ptr<Stmt> >& statements);

    /*
        pretty print the program
    */
    void print_program(std::ostream& os = std::cout) const;

    std::vector<std::shared_ptr<Stmt> > get_statements() const;

    /*
        returns true if a LET statement is eliminated,
        false if no LET statement is found
    */
    bool eliminate_let_statements();
    bool eliminate_for_statements();
    bool rename_borrow_alloc();
    /*
        evaluate all expressions in the program
        throw an error if an expression cannot be evaluated
    */
    void evaluate();
    bool free_name_check() const;

private:
    /*
        constructor
    */
    explicit Program(const std::vector<std::shared_ptr<Stmt> >& statements);


    std::vector<std::shared_ptr<Stmt> > statements_;

    int name_idx = 0;
    
};