
#pragma once

#include <memory>

class Expr; 

class Substitutable {

public:
    virtual void substitute(const std::string& name, const std::shared_ptr<Expr>& value) = 0;


};