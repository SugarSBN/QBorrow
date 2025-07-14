
#include "Preprocessor.h"

std :: vector<std :: shared_ptr<Stmt> > Preprocessor :: get_statements() const {
    return statements_;
}


bool Preprocessor :: preprocess(std :: vector<std :: shared_ptr<Function> > declarations, 
                                std :: vector<std :: shared_ptr<Stmt> > statements,
                                bool need_print_remove_let) {
    
    statements_ = remove_let(statements);

    if (need_print_remove_let) {
        debug_output_ << "---After Removing LET statements:---" << std :: endl;
        for (const auto& stmt : statements_) {
            stmt -> print_stmt(debug_output_);
            debug_output_ << std :: endl;
        }
    }
    
    return true;
}


std :: vector<std :: shared_ptr<Stmt> > Preprocessor :: remove_let(std :: vector<std :: shared_ptr<Stmt> > statements) {

    std :: vector<std :: shared_ptr<Stmt> > results;
    results.clear();

    size_t i = 0;
    for (;i < statements.size(); i++) {
        if (statements[i] -> get_type() == Stmt :: Stmt_Type :: LET) {
            break;
        }
        results.push_back(statements[i]);
    }

    if (i == statements.size()) {
        return results; // no LET statement found
    }

    const auto& let_stmt = std :: get<Stmt :: Stmt_Let>(statements[i] -> get_stmt());
    std :: string id = let_stmt.id_;
    auto expr = let_stmt.expr_;

    i++;

    /*
        search for the next LET statement with the same id
    */
    for (;i < statements.size();i++) {
        if (statements[i] -> get_type() == Stmt :: Stmt_Type :: LET) {
            const auto& let_stmt_1 = std :: get<Stmt :: Stmt_Let>(statements[i] -> get_stmt());
            if (let_stmt_1.id_ == id) { 
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