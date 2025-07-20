#include <iostream> 
#include <string>   
#include <fstream>  
#include <chrono>
#include "Argument.h"
#include "Parser.h" 
#include "Preprocessor.h"
#include "QBorrowParser.h" 
#include "Verifier_Bitwuzla.h"
#include "Verifier_CVC5.h"

#define RED "\033[1;31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(int argc, char* argv[]) {

    /*
        Argument parsing
    */
    const auto& argument_parser = Argument_Parser::make_argument_parser(std::cerr); 

    if (argument_parser -> parse_argument(argc, argv) == false) {
        std::cerr << RED << "[Argument parsing failed]" << RESET << std::endl;
        return 1;
    }
    

    /*
        Program parsing
    */
    const auto& parser = Parser::make_parser(std::cerr);

    if (parser -> parse_string(argument_parser -> get_parse_result()) == false) {
        std::cerr << RED << "[Parsing failed]" << RESET << std::endl;
        return 1;
    }

    auto program = parser -> get_program();

    if (argument_parser -> get_need_print()) {
        std::cout << (*program) << std::endl;
    }

    /*
        Preprocessing
    */
    const auto& preprocessor = Preprocessor::make_preprocessor(std::cout, std::cerr, argument_parser -> get_need_print_preprocess()); 

    if (!preprocessor -> preprocess(program)) {
        std::cerr << RED << "[Preprocessing failed]" << RESET << std::endl;
        return 1;
    } 

    const auto& verifier_bitwuzla = Verifier_Bitwuzla::make_verifier(program, std::cerr);
    verifier_bitwuzla -> interpret();

    /*
        timer for verification
    */
    using Clock = std::chrono::high_resolution_clock;
    // using std::chrono::seconds;
    Clock::time_point start_time = Clock::now();

    // interpreter -> interpret();

    if (!verifier_bitwuzla -> verify()) {
        return 1;
    }

    Clock::time_point end_time = Clock::now();
    std::chrono::seconds elapsed_bitwuzla = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    std::cout<< BLUE << "[Verification completed, all borrowed dirty qubits have been safely uncomputed]" << RESET << std::endl;

    const auto& verifier_cvc5 = Verifier_CVC5::make_verifier(program, std::cerr);
    verifier_cvc5 -> interpret();

    start_time = Clock::now();

    if (!verifier_cvc5 -> verify()) {
        return 1;
    }
    end_time = Clock::now();
    std::chrono::seconds elapsed_cvc5 = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    std::cout<< BLUE << "[Verification completed, all borrowed dirty qubits have been safely uncomputed]" << RESET << std::endl;

    std::cout<<"Bitwuzla Verification duration: " << elapsed_bitwuzla.count() << " seconds" << std::endl;
    std::cout<<"CVC5 Verification duration: " << elapsed_cvc5.count() << " seconds" << std::endl;


    return 0;
}