
#pragma once
#include <iostream>

class Printable {

public:
    friend std::ostream& operator<<(std::ostream& os, const Printable& obj);

private: 
    virtual void print(std::ostream& os) const = 0;

};
