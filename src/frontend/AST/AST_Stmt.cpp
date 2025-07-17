
#include "AST_Stmt.h"

/*
    Constructors
*/
Stmt::Stmt (Stmt_Type t, const std::string& name, const std::shared_ptr<Expr>& expr, const int& lineno)
    : stmt_(Stmt_Let{name, expr}), type_(t), lineno_(lineno) {}

Stmt::Stmt (Stmt_Type t, const std::string& name, const int& lineno) 
    : stmt_(Stmt_Rel{name}), type_(t), lineno_(lineno) {}

Stmt::Stmt (Stmt_Type t, const std::shared_ptr<Register>& reg, const int& lineno)
    : type_(t), lineno_(lineno) {
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

Stmt::Stmt (Stmt_Type t, const std::shared_ptr<Register>& control, const std::shared_ptr<Register>& target, const int& lineno) 
    : stmt_(Stmt_CNOT{control, target}), type_(t), lineno_(lineno) {}

Stmt::Stmt (Stmt_Type t, 
                const std::shared_ptr<Register>& control1, 
                const std::shared_ptr<Register>& control2, 
                const std::shared_ptr<Register>& target, 
                const int& lineno)
    : stmt_(Stmt_CCNOT{control1, control2, target}), type_(t), lineno_(lineno) {}


Stmt::Stmt (Stmt_Type t, 
                const std::string& id, 
                const std::shared_ptr<Expr>& start, 
                const std::shared_ptr<Expr>& end, 
                const std::vector<std::shared_ptr<Stmt> >& body, 
                const int& lineno) 
    : stmt_(Stmt_For{id, start, end, body}), type_(t), lineno_(lineno) {}

std::shared_ptr<Stmt> Stmt::clone() const {
    switch (type_) {
        case Stmt_Type::LET: {
            const auto& let_stmt = std::get<Stmt_Let>(stmt_);
            return make_let(let_stmt.id_, let_stmt.expr_ -> clone(), lineno_);
        }
        case Stmt_Type::BORROW: {
            const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
            return make_borrow(borrow_stmt.register_ -> clone(), lineno_);
        }
        case Stmt_Type::ALLOC: {
            const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
            return make_alloc(alloc_stmt.register_ -> clone(), lineno_);
        }
        case Stmt_Type::REL: {
            const auto& rel_stmt = std::get<Stmt_Rel>(stmt_);
            return make_rel(rel_stmt.id_, lineno_);
        }
        case Stmt_Type::X: {
            const auto& x_stmt = std::get<Stmt_X>(stmt_);
            return make_x(x_stmt.target_ -> clone(), lineno_);
        }
        case Stmt_Type::CNOT: {
            const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
            return make_cnot(cnot_stmt.control_ -> clone(), cnot_stmt.target_ -> clone(), lineno_);
        }
        case Stmt_Type::CCNOT: {
            const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
            return make_ccnot(ccnot_stmt.control1_ -> clone(), 
                              ccnot_stmt.control2_ -> clone(), 
                              ccnot_stmt.target_ -> clone(),
                              lineno_);
        }
        case Stmt_Type::FOR: {
            const auto& for_stmt = std::get<Stmt_For>(stmt_);
            std::vector<std::shared_ptr<Stmt> > new_body;
            for (const auto& body_stmt : for_stmt.body_) {
                new_body.push_back(body_stmt -> clone());
            }
            return make_for(for_stmt.id_, 
                            for_stmt.start_ -> clone(), 
                            for_stmt.end_ -> clone(), 
                            new_body, 
                            lineno_);
        }
        default:
            throw std::runtime_error("Invalid Stmt_Type for cloning");
    }
}



// Stmt factory methods

std::shared_ptr<Stmt> Stmt::make_let(const std::string& name, const std::shared_ptr<Expr>& expr, const int& lineno){
        return std::make_shared<Stmt>(Stmt(Stmt_Type::LET, name, expr, lineno));
}

std::shared_ptr<Stmt> Stmt::make_borrow(const std::shared_ptr<Register>& reg, const int& lineno) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::BORROW, reg, lineno));
}

std::shared_ptr<Stmt> Stmt::make_alloc(const std::shared_ptr<Register>& reg, const int& lineno) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::ALLOC, reg, lineno));
}

std::shared_ptr<Stmt> Stmt::make_rel(const std::string& id, const int& lineno) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::REL, id, lineno));
}

std::shared_ptr<Stmt> Stmt::make_x(const std::shared_ptr<Register>& target, const int& lineno) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::X, target, lineno));
}

std::shared_ptr<Stmt> Stmt::make_cnot(const std::shared_ptr<Register>& control, const std::shared_ptr<Register>& target, const int& lineno) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::CNOT, control, target, lineno));
}

std::shared_ptr<Stmt> Stmt::make_ccnot(const std::shared_ptr<Register>& control1, 
                                       const std::shared_ptr<Register>& control2, 
                                       const std::shared_ptr<Register>& target, 
                                       const int& lineno) { 
        return std::make_shared<Stmt>(Stmt(Stmt_Type::CCNOT, control1, control2, target, lineno));
}

std::shared_ptr<Stmt> Stmt::make_for(const std::string& id, 
                                     const std::shared_ptr<Expr>& start, 
                                     const std::shared_ptr<Expr>& end, 
                                     const std::vector<std::shared_ptr<Stmt> >& body,
                                     const int& lineno) {
        return std::make_shared<Stmt>(Stmt(Stmt_Type::FOR, id, start, end, body, lineno));
}



void Stmt::substitute(const std::string& name, const std::shared_ptr<Expr>& value) {
    switch (type_) {
        case Stmt_Type::LET: {
            const auto& let_stmt = std::get<Stmt_Let>(stmt_);
            let_stmt.expr_ -> substitute(name, value);
            break;
        }
        case Stmt_Type::BORROW: {
            const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
            borrow_stmt.register_ -> substitute(name, value);
            break;
        }
        case Stmt_Type::ALLOC: {
            const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
            alloc_stmt.register_ -> substitute(name, value);
            break;
        }
        case Stmt_Type::X: {
            const auto& x_stmt = std::get<Stmt_X>(stmt_);
            x_stmt.target_ -> substitute(name, value);
            break;
        }
        case Stmt_Type::CNOT: {
            const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
            cnot_stmt.control_ -> substitute(name, value);
            cnot_stmt.target_ -> substitute(name, value);
            break;
        }
        case Stmt_Type::CCNOT: {
            const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
            ccnot_stmt.control1_ -> substitute(name, value);
            ccnot_stmt.control2_ -> substitute(name, value);
            ccnot_stmt.target_ -> substitute(name, value);
            break;
        }
        case Stmt_Type::FOR: {
            const auto& for_stmt = std::get<Stmt_For>(stmt_);
            for_stmt.start_ -> substitute(name, value);
            for_stmt.end_ -> substitute(name, value);
            for (const auto& body_stmt : for_stmt.body_) {
                body_stmt -> substitute(name, value);
            }
            break;
        }
        case Stmt_Type::REL:
            break;
    }
}

void Stmt::substitute_reg(const std::string& name, const std::string& value) {
    try {
        switch (type_) {
            case Stmt_Type::BORROW: {
                const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
                if (borrow_stmt.register_ -> get_name() == name) {
                    borrow_stmt.register_ -> set_name(value);
                }
                break;
            }
            case Stmt_Type::ALLOC: {
                const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
                if (alloc_stmt.register_ -> get_name() == name) {
                    alloc_stmt.register_ -> set_name(value);
                }
                break;
            }
            case Stmt_Type::X: {
                const auto& x_stmt = std::get<Stmt_X>(stmt_);
                if (x_stmt.target_ -> get_name() == name) {
                    x_stmt.target_ -> set_name(value);
                }
                break;
            }
            case Stmt_Type::CNOT: {
                const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
                if (cnot_stmt.control_ -> get_name() == name) {
                    cnot_stmt.control_ -> set_name(value);
                }
                if (cnot_stmt.target_ -> get_name() == name) {
                    cnot_stmt.target_ -> set_name(value);
                }
                break;
            }
            case Stmt_Type::CCNOT: {
                const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
                if (ccnot_stmt.control1_ -> get_name() == name) {
                    ccnot_stmt.control1_ -> set_name(value);
                }
                if (ccnot_stmt.control2_ -> get_name() == name) {
                    ccnot_stmt.control2_ -> set_name(value);
                }
                if (ccnot_stmt.target_ -> get_name() == name) {
                    ccnot_stmt.target_ -> set_name(value);
                }
                break;
            }
            case Stmt_Type::FOR: {
                const auto& for_stmt = std::get<Stmt_For>(stmt_);
                
                for (const auto& body_stmt : for_stmt.body_) {
                    body_stmt -> substitute_reg(name, value);
                }
                break;
            }
            case Stmt_Type::REL: {
                auto& rel_stmt = std::get<Stmt_Rel>(stmt_);
                if (rel_stmt.id_ == name) {
                    rel_stmt.id_ = value;
                }
                break;
            }
            default:
                break;
        }
    }
    catch (const std::exception& ex) {
        throw std::runtime_error("Line " + std::to_string(lineno_) + ": " + ex.what());
    }
}

void Stmt::evaluate() {
    try{
        switch (type_) {
            case Stmt_Type::LET: {
                const auto& let_stmt = std::get<Stmt_Let>(stmt_);
                let_stmt.expr_ -> evaluate();
                break;
            }
            case Stmt_Type::BORROW: {
                const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
                borrow_stmt.register_ -> evaluate();
                break;
            }
            case Stmt_Type::ALLOC: {
                const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
                alloc_stmt.register_ -> evaluate();
                break;
            }
            case Stmt_Type::X: {
                const auto& x_stmt = std::get<Stmt_X>(stmt_);
                x_stmt.target_ -> evaluate();
                break;
            }
            case Stmt_Type::CNOT: {
                const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
                cnot_stmt.control_ -> evaluate();
                cnot_stmt.target_ -> evaluate();
                break;
            }
            case Stmt_Type::CCNOT: {
                const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
                ccnot_stmt.control1_ -> evaluate();
                ccnot_stmt.control2_ -> evaluate();
                ccnot_stmt.target_ -> evaluate();
                break;
            }
            case Stmt_Type::FOR: {
                const auto& for_stmt = std::get<Stmt_For>(stmt_);
                for_stmt.start_ -> evaluate();
                for_stmt.end_ -> evaluate();
                break;
            }
            case Stmt_Type::REL: {
                break;
            }
        }
    }
    catch (const std::exception& ex) {
        throw std::runtime_error("Line " + std::to_string(lineno_) + ": " + ex.what());
    }
}


const Stmt::Stmt_Type& Stmt::get_type() const {
    return type_;
}

const std::variant<
        Stmt::Stmt_Let,
        Stmt::Stmt_Borrow,
        Stmt::Stmt_Alloc,
        Stmt::Stmt_Rel,
        Stmt::Stmt_X,
        Stmt::Stmt_CNOT,
        Stmt::Stmt_CCNOT,
        Stmt::Stmt_For
    >& Stmt::get_stmt() const{
    return stmt_;
}

const int& Stmt::get_lineno() const {
    return lineno_;
}





/*
    pretty print statements
*/

#define RED "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Stmt::print(std::ostream& os) const {
    print_stmt(os);
}

void Stmt::print_stmt(std::ostream& os, const int& layer) const {
    for (int i = 0; i < layer; ++i) 
        os << "  ";
    
    switch (type_) {
        case Stmt_Type::LET : { 
            const auto& let_stmt = std::get<Stmt_Let>(stmt_);

            os << BLUE << "let " << RESET << let_stmt.id_ << RED << " = " << RESET << (*let_stmt.expr_) << ";";
            break;
        }
        case Stmt_Type::BORROW : {
            const auto& borrow_stmt = std::get<Stmt_Borrow>(stmt_);
            os << BLUE << "borrow " << RESET << (*borrow_stmt.register_) << ";";
            break;
        }
        case Stmt_Type::ALLOC : {
            const auto& alloc_stmt = std::get<Stmt_Alloc>(stmt_);
            os << BLUE << "alloc " << RESET << (*alloc_stmt.register_) << ";";
            break;
        }
        case Stmt_Type::REL : {
            const auto& rel_stmt = std::get<Stmt_Rel>(stmt_);
            os << BLUE << "release " << RESET << rel_stmt.id_ << ";";
            break;
        }
        case Stmt_Type::X : {
            const auto& x_stmt = std::get<Stmt_X>(stmt_);
            os << BLUE << "X" << RESET << "[" << (*x_stmt.target_) << "];";
            break;
        }
        case Stmt_Type::CNOT : {
            const auto& cnot_stmt = std::get<Stmt_CNOT>(stmt_);
            os << BLUE << "CNOT" << RESET << "[" << (*cnot_stmt.control_) << ", " << (*cnot_stmt.target_) << "];";
            break;
        }
        case Stmt_Type::CCNOT : {
            const auto& ccnot_stmt = std::get<Stmt_CCNOT>(stmt_);
            os << BLUE << "CCNOT" << RESET << "[" << (*ccnot_stmt.control1_) << ", " << (*ccnot_stmt.control2_) << ", " << (*ccnot_stmt.target_) << "];";
            break;
        }
        case Stmt_Type::FOR : {
            const auto& for_stmt = std::get<Stmt_For>(stmt_);
            os << BLUE << "for " << RESET << for_stmt.id_ << " = " << (*for_stmt.start_) << BLUE << " to " << RESET << (*for_stmt.end_) << " {";

            for (const auto& body_stmt : for_stmt.body_) {
                os << std::endl;
                body_stmt -> print_stmt(os, layer + 1);
            }
            os << std::endl;
            for (int i = 0; i < layer; ++i) os << "  ";
            os << "}";
            break;
        }
        default:
            throw std::runtime_error("Stmt print error: Invalid Stmt_Type");
    }
}