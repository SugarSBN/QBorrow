
#include "Argument.h"
#include <fstream>

Argument_Parser :: Argument_Parser(std :: ostream & error_stream) : error_output_(error_stream) {

}


void Argument_Parser :: message_absence_input_file(){
    error_output_ << RED << "[QDirty Error] Input: no input file." << std :: endl;
    error_output_ << RESET << "[QDirty Usage:] qdirty <input_file_path>";
    error_output_ << RESET << "   Example: qdirty my_source_code.qdt" << std :: endl;
}

void Argument_Parser :: message_file_open_error(const std :: string& file_path){
    error_output_ << RED << "[QDirty Error] Input: could not open input file '" << file_path << "'" << std :: endl;
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

    return true;
}

std :: string Argument_Parser :: get_parse_result() const {
    return parse_result_;
}








