#include <iostream> 
#include <string>   
#include <fstream>  
#include "Argument.h"
#include "Parser.h" 
#include "Preprocessor.h"
#include "QBorrowParser.h" 

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(int argc, char* argv[]) {

    std :: string contents;
    Argument_Parser argument_parser(std :: cerr); 

    if (argument_parser.parse_argument(argc, argv) == false) {
        std :: cerr << RED << "Argument parsing failed." << std :: endl;
        return 1;
    }


    Parser parser(std :: cerr);

    if (parser.parse_string(argument_parser.get_parse_result()) == false) {
        std :: cerr << RED << "Parsing failed." << std :: endl;
        return 1;
    }

    std :: vector<std :: shared_ptr<Stmt> > statements = parser.get_statements();
    std :: vector<std :: shared_ptr<Function> > functions = parser.get_functions();

    if (argument_parser.get_need_print()) {
        for (const auto& func : functions) {
            func -> print_function(); 
            std :: cout << std :: endl;
        }

        for (const auto& stmt : statements) {
            stmt -> print_stmt(); 
            std :: cout << std :: endl;
        }
    }

    
    Preprocessor preprocessor(std :: cout, std :: cerr);

    if (preprocessor.preprocess(functions, statements, 
                                argument_parser.get_need_print_remove_let()) == false) {
        std :: cerr << "Preprocessing failed." << std :: endl;
        return 1;
    }
    

    return 0;
}