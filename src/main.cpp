#include <iostream> 
#include <string>   
#include <fstream>  
#include "Argument.h"
#include "Parser.h" 
#include "Preprocessor.h"
#include "QBorrowParser.h" 

#define RED "\033[1;31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(int argc, char* argv[]) {

    std::string contents;

    const auto& argument_parser = Argument_Parser::make_argument_parser(std::cerr); 

    if (argument_parser -> parse_argument(argc, argv) == false) {
        std::cerr << RED << "[Argument parsing failed]" << RESET << std::endl;
        return 1;
    }
    


    const auto& parser = Parser::make_parser(std::cerr);

    if (parser -> parse_string(argument_parser -> get_parse_result()) == false) {
        std::cerr << RED << "[Parsing failed]" << RESET << std::endl;
        return 1;
    }

    auto program = parser -> get_program();

    if (argument_parser -> get_need_print()) {
        program -> print_program(std::cout);
    }

    const auto& preprocessor = Preprocessor::make_preprocessor(std::cout, std::cerr, 
                                                    argument_parser -> get_need_print_remove_let(), 
                                                    argument_parser -> get_need_print_remove_for()); 

    preprocessor -> preprocess(program);
    

    return 0;
}