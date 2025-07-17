
#pragma once

#include "Program.h"
#include "cvc5/cvc5.h"


class Interpreter {

public:


    void interpret();

    static std::shared_ptr<Interpreter> make_interpreter(const std::shared_ptr<Program>& program, 
                                                         std::ostream& error_output);

    bool verify();
    

private:
    
    explicit Interpreter(const std::shared_ptr<Program>& program, 
                         std::ostream& error_output);
    

    cvc5::TermManager tm_;
    cvc5::Solver solver_ = cvc5::Solver(tm_);


    std::vector<std::map<std::string, cvc5::Term> > semantics_;
    
    std::map<std::string, cvc5::Term> qubits_;

    std::shared_ptr<Program> program_;

    std::ostream& error_output_;


};  
