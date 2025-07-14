#include <iostream> 
#include <string>   
#include <fstream>  
#include "Argument.h"
#include "Parser.h" 
#include "QBorrowParser.h" 

int main(int argc, char* argv[]) {

    std :: string contents;
    Argument_Parser argument_parser(std :: cerr); 

    if (argument_parser.parse_argument(argc, argv) == false) 
        return 1;

    // std :: cout << argument_parser.get_parse_result() << std :: endl;

    Parser parser(std :: cerr);

    if (parser.parse_string(argument_parser.get_parse_result()) == true){
        /* */
    }
    std :: vector<std :: shared_ptr<Stmt> > statements = parser.get_statements();

    // std :: cout << "Parsed statements:" << std :: endl;

    for (const auto& stmt : statements) {
        stmt -> print_stmt(); 
        std :: cout << std :: endl;
    }

    return 0;
}