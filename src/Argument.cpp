
#include "Argument.h"
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"      

Argument_Parser :: Argument_Parser(std :: ostream & error_stream) : error_output_(error_stream) {

}


void Argument_Parser :: message_absence_input_file(){
    error_output_ << RED << "[QBorrow Error] Input: no input file." << std :: endl;
    error_output_ << RESET << "[QBorrow Usage:] qborrow <input_file_path>";
    error_output_ << RESET << "   Example: qborrow ../example/eg1.qbr" << std :: endl;
}

void Argument_Parser :: message_file_open_error(const std :: string& file_path){
    error_output_ << RED << "[QBorrow Error] Input: could not open input file '" << file_path << "'" << std :: endl;
}

bool Argument_Parser :: parse_argument(int argc, char* argv[]){
    if (argc < 2) { 
        message_absence_input_file();
        return false; 
    }

    std :: ifstream input_file(argv[1]);

    if (!input_file.is_open()) {
        message_file_open_error(argv[1]);
        return "";
    }    

    parse_result_ = "";
    std :: string line;
    while (std :: getline(input_file, line)) 
        parse_result_ += line + "\n";

    input_file.close(); 


    int idx = 2;
    while (idx < argc) {
        if (std :: string(argv[idx]) == "--pretty-print") {
            need_print_ = true;
        } else {
            error_output_ << RED << "[QBorrow Error] Unknown argument: " << argv[idx] << RESET << std :: endl;
            return false;
        }
        idx++;
    }


    return true;
}

std :: string Argument_Parser :: get_parse_result() const {
    return parse_result_;
}

bool Argument_Parser :: get_need_print() const {
    return need_print_;
}







