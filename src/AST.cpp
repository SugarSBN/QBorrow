
#include "AST.h"
#include <string>





// Expr factory methods

std :: shared_ptr<Expr> Expr :: make_variable(const std :: string& name) { 
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: ID,
        Expr_ID{name}
    });
}


std :: shared_ptr<Expr> Expr :: make_number(int value) {
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: NUMBER,
        Expr_Number{value}
    });
}


std :: shared_ptr<Expr> Expr :: make_unary_op(Unary_Op op, std :: shared_ptr<Expr> operand) {
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: UnaryOp,
        Expr_Unary_Op{op, std :: move(operand)}
    });
}


std :: shared_ptr<Expr> Expr :: make_binary_op(Binary_Op op,
                                                std :: shared_ptr<Expr> left,
                                                std :: shared_ptr<Expr> right) {
    return std :: make_shared<Expr>(Expr{
        Expr_Type :: BinaryOp,
        Expr_Binary_Op{op, std :: move(left), std :: move(right)}
    });
}


/*
    register factory method
*/
std :: shared_ptr<Register> Register :: make_register(const std :: string& name, std :: shared_ptr<Expr> size) {
    return std :: make_shared<Register>(Register{
        name, 
        std :: move(size)
    });
}

/*
    function factory method
*/
std :: shared_ptr<Function> Function :: make_function(const std :: string& name, 
                                            const std :: vector<std :: string>& params, 
                                            const std :: vector<std :: shared_ptr<Register> >& registers,
                                            const std :: vector<std :: shared_ptr<Stmt> >& body) {
    return std :: make_shared<Function>(name, params, registers, body);
}


// Stmt factory methods

std :: shared_ptr<Stmt> Stmt :: make_let(const std :: string& name, std :: shared_ptr<Expr> expr){
        return std :: make_shared<Stmt>(Stmt_Type :: LET, name, std :: move(expr));
}

std :: shared_ptr<Stmt> Stmt :: make_borrow(std :: shared_ptr<Register> reg) {
        return std :: make_shared<Stmt>(Stmt_Type :: BORROW, std :: move(reg));
}

std :: shared_ptr<Stmt> Stmt :: make_alloc(std :: shared_ptr<Register> reg) {
        return std :: make_shared<Stmt>(Stmt_Type :: ALLOC, std :: move(reg));
}

std :: shared_ptr<Stmt> Stmt :: make_rel(const std :: string& id) {
        return std :: make_shared<Stmt>(Stmt_Type :: REL, id);
}


std :: shared_ptr<Stmt> Stmt :: make_x(std :: shared_ptr<Register> target) {
        return std :: make_shared<Stmt>(Stmt_Type :: X, std :: move(target));
}

std :: shared_ptr<Stmt> Stmt :: make_cnot(std :: shared_ptr<Register> control, std :: shared_ptr<Register> target) {
        return std :: make_shared<Stmt>(Stmt_Type :: CNOT, std :: move(control), std :: move(target));
}

std :: shared_ptr<Stmt> Stmt :: make_ccnot(std :: shared_ptr<Register> control1, 
                                              std :: shared_ptr<Register> control2, 
                                              std :: shared_ptr<Register> target) { 
        return std :: make_shared<Stmt>(Stmt_Type::CCNOT, std :: move(control1), std :: move(control2), std :: move(target));
}
std :: shared_ptr<Stmt> Stmt :: make_for(const std :: string& id, 
                                            std :: shared_ptr<Expr> start, 
                                            std :: shared_ptr<Expr> end, 
                                            std :: vector<std :: shared_ptr<Stmt>> body) {
        return std :: make_shared<Stmt>(Stmt_Type::FOR, id, std :: move(start), std :: move(end), std :: move(body));
}




Stmt :: Stmt_Type Stmt :: get_type() const {
    return type_;
}


/*
        pretty print expressions
*/
#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Expr :: print_expr(std :: ostream& os) const {
        switch (type_) {
            case Expr_Type :: ID:
                os << std :: get<Expr_ID>(expr_).id_;
                break;
            case Expr_Type :: NUMBER:
                os << std :: get<Expr_Number>(expr_).number_;
                break;
            case Expr_Type :: UnaryOp: {
                const auto& unary = std :: get<Expr_Unary_Op>(expr_);

                switch (unary.op_) {
                    case Unary_Op :: NEGATE: os << "-"; break;
                }

                os << "(";
                unary.operand_ -> print_expr(os);
                os << ")";
                break;
            }
            case Expr_Type :: BinaryOp: {
                const auto& binary = std :: get<Expr_Binary_Op>(expr_);

                os << "(";
                binary.left_ -> print_expr(os);

                switch (binary.op_) {
                    case Binary_Op :: ADD: os << RED << "+" << RESET; break;
                    case Binary_Op :: MUL: os << RED << "*" << RESET; break;
                    case Binary_Op :: SUB: os << RED << "-" << RESET; break;
                }
                binary.right_ -> print_expr(os);
                os << ")";
                break;
            }
        }
    }

void Register :: print_register(std :: ostream& os) const {
    os << name_;
    if (size_ != nullptr) {
        os << "["; 
        size_ -> print_expr(os);
        os << "]";
    }
}

void Stmt :: print_stmt(std :: ostream& os, int layer) const {
    for (int i = 0; i < layer; ++i) 
        os << "  ";

    switch (type_) {
        case Stmt_Type :: LET : { 
            const auto& let_stmt = std :: get<Stmt_Let>(stmt_);
            os << BLUE << "let " << RESET << let_stmt.id_ << RED << " = " << RESET;
            let_stmt.expr_ -> print_expr(os);
            os << ";";
            break;
        }
        case Stmt_Type :: BORROW : {
            const auto& borrow_stmt = std :: get<Stmt_Borrow>(stmt_);
            os << BLUE << "borrow " << RESET << borrow_stmt.register_ -> name_;
            borrow_stmt.register_ -> print_register(os);
            os << ";";
            break;
        }
        case Stmt_Type :: ALLOC : {
            const auto& alloc_stmt = std :: get<Stmt_Alloc>(stmt_);
            os << BLUE << "alloc " << RESET;
            alloc_stmt.register_ -> print_register(os);
            os << ";";
            break;
        }
        case Stmt_Type :: REL : {
            const auto& rel_stmt = std :: get<Stmt_Rel>(stmt_);
            os << BLUE << "release " << RESET << rel_stmt.id_ << ";";
            break;
        }
        case Stmt_Type :: X : {
            const auto& x_stmt = std :: get<Stmt_X>(stmt_);
            os << BLUE << "X" << RESET;
            os << "[";
            x_stmt.target_ -> print_register(os);
            os << "];";
            break;
        }
        case Stmt_Type :: CNOT : {
            const auto& cnot_stmt = std :: get<Stmt_CNOT>(stmt_);
            os << BLUE << "CNOT" << RESET;
            os << "[";
            cnot_stmt.control_ -> print_register(os);
            os << ", ";
            cnot_stmt.target_ -> print_register(os);
            os << "];";
            break;
        }
        case Stmt_Type :: CCNOT : {
            const auto& ccnot_stmt = std :: get<Stmt_CCNOT>(stmt_);
            os << BLUE << "CCNOT" << RESET;
            os << "[";
            ccnot_stmt.control1_ -> print_register(os);
            os << ", ";
            ccnot_stmt.control2_ -> print_register(os);
            os << ", ";
            ccnot_stmt.target_ -> print_register(os);
            os << "];";
            break;
        }
        case Stmt_Type :: FOR : {
            const auto& for_stmt = std :: get<Stmt_For>(stmt_);
            os << BLUE << "for " << RESET << for_stmt.id_ << " = ";
            for_stmt.start_ -> print_expr(os);
            os << BLUE << " to " << RESET;
            for_stmt.end_ -> print_expr(os);
            os << " {";
            
            for (const auto& body_stmt : for_stmt.body_) {
                os << std :: endl;
                body_stmt -> print_stmt(os, layer + 1);
            }
            
            os << std :: endl << "}";
            break;
        }
    }
}


void Function :: print_function(std :: ostream& os) const {
    os << BLUE << "function " << RESET << name_ << "(";
    for (size_t i = 0; i < params_.size(); i++) {
        os << params_[i];
        if (i < params_.size() - 1) {
            os << ", ";
        }
    }
    os << ") [";

    for (const auto& reg : registers_) {
        reg -> print_register(os);
        os << ",  ";
    }

    os << "] {";

    for (const auto& stmt : body_) {
        os << std :: endl;
        stmt -> print_stmt(os, 1);
    }

    os << std :: endl << "}";
}