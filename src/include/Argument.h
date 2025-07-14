#pragma once

#include <iostream>
#include <string>


class Argument_Parser{

public:
    
    /*
        constructor, taking an error output stream
    */
    explicit Argument_Parser(std :: ostream & error_stream);

    /*
        parse the command line arguments
        returns true if parsing is successful, false otherwise
    */
    bool parse_argument(int argc, char* argv[]);

    /*
        interface to get the result of parsing arguments
    */
    std :: string get_parse_result() const;
    bool get_need_print() const;

private:

    /*
        stream for error output
    */ 
    std :: ostream & error_output_;

    /*
        the result of parsing arguments
    */ 
    std :: string parse_result_;

    bool need_print_ = false;

    
    /*
        error messages when parsing arguments
    */
    void message_absence_input_file();
    void message_file_open_error(const std :: string& file_path);

};