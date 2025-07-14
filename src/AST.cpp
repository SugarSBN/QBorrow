
#include "AST.h"
#include <string>

Stmt :: Stmt (Stmt_Type t, const std :: string& name, std :: shared_ptr<Expr> expr)
        : stmt_(Stmt_Let{name, *expr}), type_(t) {}