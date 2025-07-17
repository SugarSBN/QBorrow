
#pragma once

#include "AST_Expr.h"
#include "AST_Register.h"
#include "AST_Stmt.h"


class Program final : public Printable, public Evaluatable, public Substitutable {

public:
    
    /*
        factory method to create a program
    */
    static std::shared_ptr<Program> make_program(const std::vector<std::shared_ptr<Stmt> >& statements);




    void print(std::ostream& os) const override;
    void substitute(const std::string& name, const std::shared_ptr<Expr>& value) override;
    void evaluate() override;


    const std::vector<std::shared_ptr<Stmt> >& get_statements() const;


    /*
        returns true if a LET statement is eliminated,
        false if no LET statement is found
    */
    bool eliminate_let_statements();
    bool eliminate_for_statements();
    bool rename_borrow_alloc();

    /*
        well-formed checking
    */
    void check_free_name() const;
    void check_out_range() const;
    void check_disjoint() const;

private:
    /*
        constructor
    */
    explicit Program(const std::vector<std::shared_ptr<Stmt> >& statements);


    std::vector<std::shared_ptr<Stmt> > statements_;

    int name_idx_ = 0;
    
};