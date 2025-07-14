#pragma once

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

class Argument_Parser{

public:
    explicit Argument_Parser(std :: ostream & error_stream);

    bool parse_argument(int argc, char* argv[]);

    std :: string get_parse_result() const;

private:
    std :: ostream & error_output_;
    std :: string parse_result_;

    void message_absence_input_file();
    void message_file_open_error(const std :: string& file_path);

};