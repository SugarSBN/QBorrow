
#include "Preprocessor.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"  

Preprocessor::Preprocessor(std::ostream& debug_output, 
                           std::ostream& error_output,
                           bool need_print)
    : debug_output_(debug_output), 
      error_output_(error_output), 
      need_print_(need_print) {}

std::shared_ptr<Preprocessor> Preprocessor::make_preprocessor(std::ostream& debug_output, 
                                                              std::ostream& error_output,
                                                              bool need_print) {
    return std::make_shared<Preprocessor>(Preprocessor(debug_output, error_output, need_print));
}

void Preprocessor::preprocess(std::shared_ptr<Program>& program) {
    try {

        while (program -> eliminate_let_statements());

        while (program -> eliminate_for_statements());

        program -> evaluate();

        while(program -> rename_borrow_alloc());

        program -> check_free_name();
        program -> check_out_range();
        program -> check_disjoint();

        if (need_print_) {
            debug_output_ << "Preprocessing completed successfully." << std::endl;
            debug_output_ << (*program) << std::endl;
        }
    }
    catch (const std::exception& ex) {
        error_output_ << RED << "[Preprocessing failed] " << ex.what() << RESET << std::endl;
        debug_output_ << "Last processed program:" << std::endl;
        debug_output_ << (*program) << std::endl;
        return;
    }
}