
#include "Preprocessor.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"  

Preprocessor::Preprocessor(std::ostream& debug_output, 
                           std::ostream& error_output,
                           bool need_print_remove_let,
                           bool need_print_remove_for)
    : debug_output_(debug_output), 
      error_output_(error_output), 
      need_print_remove_let_(need_print_remove_let), 
      need_print_remove_for_(need_print_remove_for) {}

std::shared_ptr<Preprocessor> Preprocessor::make_preprocessor(std::ostream& debug_output, 
                                                              std::ostream& error_output,
                                                              bool need_print_remove_let,
                                                              bool need_print_remove_for) {
    return std::make_shared<Preprocessor>(Preprocessor(debug_output, error_output, need_print_remove_let, need_print_remove_for));
}

void Preprocessor::preprocess(std::shared_ptr<Program>& program) {
    try {
        while (program -> eliminate_let_statements());
        if (need_print_remove_let_) {
            debug_output_ << "---After Removing LET statements:---" << std::endl;
            program -> print_program(debug_output_);    
        }

        while (program -> eliminate_for_statements());
        if (need_print_remove_for_) {
            debug_output_ << "---After Removing FOR statements:---" << std::endl;
            program -> print_program(debug_output_);
        }

        program -> evaluate();

        while(program -> rename_borrow_alloc());

        if (!program -> free_name_check()) {
            throw std::runtime_error("some referenced registers are not allocated or borrowed.");
        }

        program -> print_program(debug_output_);

    }
    catch (const std::exception& ex) {
        error_output_ << RED << "[Preprocessing failed] " << ex.what() << RESET << std::endl;
        debug_output_ << "Last processed program:" << std::endl;
        program -> print_program(debug_output_);
        return;
    }
}