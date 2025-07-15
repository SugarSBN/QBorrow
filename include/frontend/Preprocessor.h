
#pragma once

#include "Program.h"
#include <iostream>

class Preprocessor {

public:
    
    /*
        factory method
    */
    static std::shared_ptr<Preprocessor> make_preprocessor(std::ostream& debug_output, std::ostream& error_output);


    // bool preprocess(std::shared_ptr<Program> program,
                    // bool need_print_remove_let = true,
                    // bool need_print_remove_for = true);
    
    std::shared_ptr<Program> get_program() const;

private:
    
    /*
        constructor, taking an error output stream
    */
    explicit Preprocessor(std::ostream& debug_output, std::ostream& error_output);
    /*
        stream for output
    */ 
    std::ostream& debug_output_;
    std::ostream& error_output_;

    std::shared_ptr<Program> program_;

    std::vector<std::shared_ptr<Stmt> > remove_let(std::vector<std::shared_ptr<Stmt> > statements);
    // std::vector<std::shared_ptr<Stmt> > remove_for(std::vector<std::shared_ptr<Stmt> > statements);

};