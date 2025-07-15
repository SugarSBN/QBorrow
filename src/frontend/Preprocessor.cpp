
#include "Preprocessor.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"  

Preprocessor::Preprocessor(std::ostream& debug_output, std::ostream& error_output)
    : debug_output_(debug_output), error_output_(error_output) {}

std::shared_ptr<Preprocessor> Preprocessor::make_preprocessor(std::ostream& debug_output, std::ostream& error_output) {
    return std::make_shared<Preprocessor>(Preprocessor(debug_output, error_output));
}

std::shared_ptr<Program> Preprocessor::get_program() const {
    return program_;
}

// bool Preprocessor::preprocess(std::vector<std::shared_ptr<Function> > functions, 
//                                 std::vector<std::shared_ptr<Stmt> > statements,
//                                 bool need_print_remove_let,
//                                 bool need_print_remove_for) {

          
   
//     try {
//         /* 
//             remove LET statements in function declarations and statements
//         */             
//         std::vector<std::shared_ptr<Function> > functions_remove_let;
//         functions_remove_let.clear();
        
//         for (const auto& func : functions) {
//             functions_remove_let.push_back(
//                 Function::make_function(func -> get_name(), 
//                                         func -> get_params(), 
//                                         func -> get_registers(), 
//                                         remove_let(func -> get_body()))
//             );
//         }

//         std::vector<std::shared_ptr<Stmt> > statements_remove_let = remove_let(statements);

//         if (need_print_remove_let) {
//             debug_output_ << "---After Removing LET statements:---" << std::endl;
//             for (const auto& func : functions_remove_let) {
//                 func -> print_function(debug_output_);
//                 debug_output_ << std::endl;
//             }
//             for (const auto& stmt : statements_remove_let) {
//                 stmt -> print_stmt(debug_output_);
//                 debug_output_ << std::endl;
//             }
//         }

        /*
            remove for statements
        // */
        // std::vector<std::shared_ptr<Function> > functions_remove_for;
        // functions_remove_for.clear();
        
        // for (const auto& func : functions_remove_let) {
        //     functions_remove_for.push_back(
        //         Function::make_function(func -> name_, func -> params_, func -> registers_, remove_for(func -> body_))
        //     );
        // }

        // std::vector<std::shared_ptr<Stmt> > statements_remove_for = remove_for(statements);

        // if (need_print_remove_for) {
        //     debug_output_ << statements_remove_for.size() << std::endl;
        //     debug_output_ << "---After Removing FOR statements:---" << std::endl;
        //     for (const auto& func : functions_remove_for) {
        //         func -> print_function(debug_output_);
        //         debug_output_ << std::endl;
        //     }
        //     for (const auto& stmt : statements_remove_for) {
        //         stmt -> print_stmt(debug_output_);
        //         debug_output_ << std::endl;
        //     }
        // }

//     }
//     catch (const std::exception& e) {
//         error_output_ << RED << "[Preprocess failed] " << e.what() << RESET << std::endl;
//         return false;
//     }

//     return true;
// }


std::vector<std::shared_ptr<Stmt> > Preprocessor::remove_let(std::vector<std::shared_ptr<Stmt> > statements) {

    std::vector<std::shared_ptr<Stmt> > results;
    results.clear();

    size_t i = 0;
    for (;i < statements.size(); i++) {
        if (statements[i] -> get_type() == Stmt::Stmt_Type::LET) {
            break;
        }
        results.push_back(statements[i]);
    }

    if (i == statements.size()) {
        return results; // no LET statement found
    }

    std::string id = get<Stmt::Stmt_Let>(statements[i] -> get_stmt()).id_;
    auto expr = get<Stmt::Stmt_Let>(statements[i] -> get_stmt()).expr_;

    i++;

    /*
        search for the next LET statement with the same id
    */
    for (;i < statements.size();i++) {
        if (statements[i] -> get_type() == Stmt::Stmt_Type::LET) {
            if (std::get<Stmt::Stmt_Let>(statements[i] -> get_stmt()).id_ == id) { 
                /*
                    if we find a LET statement with the same id,
                    we substitute the previous one with the current one
                    and break
                */
                results.push_back(statements[i++] -> substitute(id, expr));
                break;
            }
        }

        results.push_back(statements[i] -> substitute(id, expr));
        
    }



    for (;i < statements.size();i++) {
        
        results.push_back(statements[i]);

    }

    return remove_let(results);

}


// std::vector<std::shared_ptr<Stmt> > Preprocessor::remove_for(std::vector<std::shared_ptr<Stmt> > statements) {
//     std::vector<std::shared_ptr<Stmt> > results;
//     results.clear();

//     size_t i = 0;

//     for (;i < statements.size(); i++) {
//         if (statements[i] -> get_type() == Stmt::Stmt_Type::FOR) {
//             break;
//         }
//         results.push_back(statements[i]);
//     }

//     if (i == statements.size()) {
//         return results; // no FOR statement found
//     }


//     const auto& for_stmt = std::get<Stmt::Stmt_For>(statements[i] -> get_stmt());
//     int start = for_stmt.start_ -> evaluate();
//     int end = for_stmt.end_ -> evaluate();
    
//     debug_output_ << for_stmt.body_.size() << std::endl;

//     for (int j = start; j < end; j++) {
//         for (auto const& body_stmt : for_stmt.body_) {
//             results.push_back(body_stmt -> substitute(for_stmt.id_, Expr::make_number(j)));
//         }
//     }

//     i++;
//     for (;i < statements.size(); i++) {
//         if (statements[i] -> get_type() == Stmt::Stmt_Type::FOR) {
//             break;
//         }
//         results.push_back(statements[i]);
//     }

//     return remove_for(results);
// }