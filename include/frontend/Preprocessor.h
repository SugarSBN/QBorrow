
#pragma once

#include "AST.h"
#include <iostream>

class Preprocessor {

public:
    /*
        constructor, taking an error output stream
    */
    explicit Preprocessor(std :: ostream& debug_output, std :: ostream& error_output)
        : debug_output_(debug_output), error_output_(error_output) {}

    std :: vector<std :: shared_ptr<Stmt> > get_statements() const;

    bool preprocess(std :: vector<std :: shared_ptr<Function> > functions,
                    std :: vector<std :: shared_ptr<Stmt> > statements,
                    bool need_print_remove_let = true);

private:
    /*
        stream for output
    */ 
    std :: ostream& debug_output_;
    std :: ostream& error_output_;

    std :: vector<std :: shared_ptr<Stmt> > statements_;
    std :: vector<std :: shared_ptr<Function> > functions_;

    std :: vector<std :: shared_ptr<Stmt> > remove_let(std :: vector<std :: shared_ptr<Stmt> > statements);
};