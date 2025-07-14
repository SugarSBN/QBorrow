#include <iostream> // 用于输入输出，例如 std :: cout 和 std :: cerr
#include <string>   // 用于使用 std :: string 处理文件路径
#include <fstream>  // 用于文件操作，例如 std :: ifstream
#include "Argument.h"
#include "Parser.h" 
#include "QDirtyParser.h" 

int main(int argc, char* argv[]) {
    // 1. 检查参数数量
    std :: string contents;
    Argument_Parser argument_parser(std :: cerr); 

    if (argument_parser.parse_argument(argc, argv) == false) 
        return 1;

    // std :: cout << argument_parser.get_parse_result() << std :: endl;

    Parser parser(std :: cerr);

    if (parser.parse_string(argument_parser.get_parse_result()) == true){
        /* */
    }
    // std :: cout << "Yes" << std :: endl;
    // std :: cout << (parser.get_parse_tree() == nullptr) << std :: endl;

    parser.get_parse_tree() -> print_stmt(std :: cout);

    return 0;
}