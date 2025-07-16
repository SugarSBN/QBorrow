
#pragma once

#include "Program.h"
#include <iostream>

class Preprocessor {

public:
    
    /*
        factory method
    */
    static std::shared_ptr<Preprocessor> make_preprocessor(std::ostream& debug_output, 
                                                           std::ostream& error_output,
                                                           bool need_print = true);

    /*
        preprocess the program, removing LET and FOR statements
    */
    void preprocess(std::shared_ptr<Program>& program);

private:
    
    /*
        constructor, taking an error output stream
    */
    explicit Preprocessor(std::ostream& debug_output, 
                          std::ostream& error_output,
                          bool need_print = true);
    /*
        stream for output
    */ 
    std::ostream& debug_output_;
    std::ostream& error_output_;

    
    bool need_print_;
};