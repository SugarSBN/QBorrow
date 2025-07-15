
#include "AST_Stmt.h"

/*
    Constructors
*/
Stmt::Stmt (Stmt_Type t, const std::string& name, const std::shared_ptr<Expr>& expr)
    : stmt_(Stmt_Let{name, expr}), type_(t) {}

Stmt::Stmt (Stmt_Type t, const std::string& name) 
    : stmt_(Stmt_Rel{name}), type_(t) {}

Stmt::Stmt (Stmt_Type t, const std::shared_ptr<Register>& reg)
    : type_(t) {
    switch (t) {
        case Stmt_Type::BORROW:
            stmt_ = Stmt_Borrow{reg};
            break;
        case Stmt_Type::ALLOC:
            stmt_ = Stmt_Alloc{reg};
            break;
        case Stmt_Type::X:
            stmt_ = Stmt_X{reg};
            break;
        default:
            throw std::runtime_error("Invalid Stmt_Type for Register");
    }
}

Stmt::Stmt (Stmt_Type t, const std::shared_ptr<Register>& control, const std::shared_ptr<Register>& target) 
    : stmt_(Stmt_CNOT{control, target}), type_(t) {}

Stmt::Stmt (Stmt_Type t, 
                const std::shared_ptr<Register>& control1, 
                const std::shared_ptr<Register>& control2, 
                const std::shared_ptr<Register>& target)
    : stmt_(Stmt_CCNOT{control1, control2, target}), type_(t) {}


Stmt::Stmt (Stmt_Type t, 
                const std::string& id, 
                const std::shared_ptr<Expr>& start, 
                const std::shared_ptr<Expr>& end, 
                const std::vector<std::shared_ptr<Stmt> >& body) 
    : stmt_(Stmt_For{id, start, end, body}), type_(t) {}

Stmt::Stmt (Stmt_Type t, 
                const std::string& function_name, 
                const std::vector<std::shared_ptr<Expr> >& args,
                const std::vector<std::shared_ptr<Register> >& regs)
    : stmt_(Stmt_Call{function_name, args, regs}), type_(t) {}



// Stmt factory methods

std::shared_ptr<Stmt> Stmt::make_let(const std::string& name, const std::shared_ptr<Expr>& expr){
        return std::make_shared<Stmt>(Stmt(Stmt_Type::LET, name, expr));
}

std::shared_ptr<Stmt> Stmt::make_borrow(const std::shared_ptr<Register>& reg) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::BORROW, reg));
}

std::shared_ptr<Stmt> Stmt::make_alloc(const std::shared_ptr<Register>& reg) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::ALLOC, reg));
}

std::shared_ptr<Stmt> Stmt::make_rel(const std::string& id) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::REL, id));
}

std::shared_ptr<Stmt> Stmt::make_x(const std::shared_ptr<Register>& target) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::X, target));
}

std::shared_ptr<Stmt> Stmt::make_cnot(const std::shared_ptr<Register>& control, const std::shared_ptr<Register>& target) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::CNOT, control, target));
}

std::shared_ptr<Stmt> Stmt::make_ccnot(const std::shared_ptr<Register>& control1, 
                                       const std::shared_ptr<Register>& control2, 
                                       const std::shared_ptr<Register>& target) { 
        return std::make_shared<Stmt>(Stmt(Stmt_Type::CCNOT, control1, control2, target));
}

std::shared_ptr<Stmt> Stmt::make_for(const std::string& id, 
                                     const std::shared_ptr<Expr>& start, 
                                     const std::shared_ptr<Expr>& end, 
                                     const std::vector<std::shared_ptr<Stmt> >& body) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::FOR, id, start, end, body));
}

std::shared_ptr<Stmt> Stmt::make_call(const std::string& function_name, 
                                      const std::vector<std::shared_ptr<Expr> >& args,
                                      const std::vector<std::shared_ptr<Register> >& regs) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::CALL, function_name, args, regs));
}


std::shared_ptr<Stmt> Stmt::substitute(const std::string& name, const std::shared_ptr<Expr>& value) const {
    switch (type_) {
        case Stmt_Type::LET: {
            const auto& let_stmt = std::get<Stmt_Let>(stmt_);
            return Stmt::make_let(let_stmt.id_, let_stmt.expr_ ? let_stmt.expr_ -> substitute(name, value) : nullptr);
        }
        case Stmt_Type::BORROW: {
            const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
            return Stmt::make_borrow(borrow_stmt.register_ -> substitute(name, value));
        }
        case Stmt_Type::ALLOC: {
            const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
            return Stmt::make_alloc(alloc_stmt.register_ -> substitute(name, value));
        }
        case Stmt_Type::X: {
            const auto& x_stmt = std::get<Stmt_X>(stmt_);
            return Stmt::make_x(x_stmt.target_ -> substitute(name, value));
        }
        case Stmt_Type::CNOT: {
            const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
            return Stmt::make_cnot(cnot_stmt.control_ -> substitute(name, value), cnot_stmt.target_ -> substitute(name, value));
        }
        case Stmt_Type::CCNOT: {
            const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
            return Stmt::make_ccnot(ccnot_stmt.control1_ -> substitute(name, value), 
                                      ccnot_stmt.control2_ -> substitute(name, value), 
                                      ccnot_stmt.target_ -> substitute(name, value));
        }
        case Stmt_Type::FOR: {
            const auto& for_stmt = std::get<Stmt_For>(stmt_);
            std::vector<std::shared_ptr<Stmt> > new_body;
            new_body.clear();
            for (const auto& body_stmt : for_stmt.body_) {
                new_body.push_back(body_stmt -> substitute(name, value));
            }
            return Stmt::make_for(for_stmt.id_, for_stmt.start_ -> substitute(name, value), 
                                  for_stmt.end_ -> substitute(name, value), new_body);
        }
        case Stmt_Type::CALL: {
            const auto& call_stmt = std::get<Stmt_Call>(stmt_);

            std::vector<std::shared_ptr<Expr> > new_args;
            for (const auto& arg : call_stmt.args_) {
                new_args.push_back(arg -> substitute(name, value));
            }

            std::vector<std::shared_ptr<Register> > new_regs;
            for (const auto& reg : call_stmt.regs_) {
                new_regs.push_back(reg -> substitute(name, value));
            }
            return Stmt::make_call(call_stmt.function_name_, std::move(new_args), std::move(new_regs));
        }
        case Stmt_Type::REL:
            return Stmt::make_rel(std::get<Stmt_Rel>(stmt_).id_);
        default:
            throw std::runtime_error("Stmt substitute error: Invalid Stmt_Type");
    }
}


Stmt::Stmt_Type Stmt::get_type() const {
    return type_;
}

std::variant<
        Stmt::Stmt_Let,
        Stmt::Stmt_Borrow,
        Stmt::Stmt_Alloc,
        Stmt::Stmt_Rel,
        Stmt::Stmt_X,
        Stmt::Stmt_CNOT,
        Stmt::Stmt_CCNOT,
        Stmt::Stmt_For,
        Stmt::Stmt_Call
    > Stmt::get_stmt() const{
    return stmt_;
}




/*
    pretty print statements
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Stmt::print_stmt(std::ostream& os, const int& layer) const {
    for (int i = 0; i < layer; ++i) 
        os << "  ";

    switch (type_) {
        case Stmt_Type::LET : { 
            const auto& let_stmt = std::get<Stmt_Let>(stmt_);
            os << BLUE << "let " << RESET << let_stmt.id_ << RED << " = " << RESET;
            let_stmt.expr_ -> print_expr(os);
            os << ";";
            break;
        }
        case Stmt_Type::BORROW : {
            const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
            os << BLUE << "borrow " << RESET;
            borrow_stmt.register_ -> print_register(os);
            os << ";";
            break;
        }
        case Stmt_Type::ALLOC : {
            const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
            os << BLUE << "alloc " << RESET;
            alloc_stmt.register_ -> print_register(os);
            os << ";";
            break;
        }
        case Stmt_Type::REL : {
            const auto& rel_stmt = std::get<Stmt_Rel>(stmt_);
            os << BLUE << "release " << RESET << rel_stmt.id_ << ";";
            break;
        }
        case Stmt_Type::X : {
            const auto& x_stmt = std::get<Stmt_X>(stmt_);
            os << BLUE << "X" << RESET;
            os << "[";
            x_stmt.target_ -> print_register(os);
            os << "];";
            break;
        }
        case Stmt_Type::CNOT : {
            const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
            os << BLUE << "CNOT" << RESET;
            os << "[";
            cnot_stmt.control_ -> print_register(os);
            os << ", ";
            cnot_stmt.target_ -> print_register(os);
            os << "];";
            break;
        }
        case Stmt_Type::CCNOT : {
            const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
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
        case Stmt_Type::FOR : {
            const auto& for_stmt = std::get<Stmt_For>(stmt_);
            os << BLUE << "for " << RESET << for_stmt.id_ << " = ";
            for_stmt.start_ -> print_expr(os);
            os << BLUE << " to " << RESET;
            for_stmt.end_ -> print_expr(os);
            os << " {";
            
            for (const auto& body_stmt : for_stmt.body_) {
                os << std::endl;
                body_stmt -> print_stmt(os, layer + 1);
            }
            os << std::endl;
            for (int i = 0; i < layer; ++i) os << "  ";
            os << "}";
            break;
        }
        case Stmt_Type::CALL : {
            const auto& call_stmt = std::get<Stmt_Call>(stmt_);
            os << BLUE << "call " << RESET << call_stmt.function_name_ << "(";
            for (size_t i = 0; i < call_stmt.args_.size(); ++i) {
                call_stmt.args_[i] -> print_expr(os);
                if (i < call_stmt.args_.size() - 1) {
                    os << ", ";
                }
            }
            os << ") [";
            for (size_t i = 0; i < call_stmt.regs_.size(); ++i) {
                call_stmt.regs_[i] -> print_register(os);
                if (i < call_stmt.regs_.size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            os << ";";
            break;
        }
        default:
            throw std::runtime_error("Stmt print error: Invalid Stmt_Type");
    }
}