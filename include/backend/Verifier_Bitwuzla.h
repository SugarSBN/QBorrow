
#pragma once

#include "Program.h"
#include "bitwuzla/cpp/bitwuzla.h"


class Verifier_Bitwuzla {

public:



    static std::shared_ptr<Verifier_Bitwuzla> make_verifier(const std::shared_ptr<Program>& program, 
                                                         std::ostream& error_output);

    void interpret();
    bool verify();
    

private:
    
    explicit Verifier_Bitwuzla(const std::shared_ptr<Program>& program, 
                         std::ostream& error_output);
    

    bitwuzla::TermManager tm_;
    bitwuzla::Options options_;
    bitwuzla::Sort bool_sort_;

    // cvc5::Solver solver_ = cvc5::Solver(tm_);


    std::vector<std::map<std::string, bitwuzla::Term> > semantics_;
    std::map<std::string, bitwuzla::Term> qubits_;

    std::shared_ptr<Program> program_;

    std::ostream& error_output_;


};  
