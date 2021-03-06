#ifndef CLASS_CONSTRUCTOR_H
#define CLASS_CONSTRUCTOR_H

#include <vector>
#include <sstream>
#include "Variable.h"

class Constructor {
private:
    std::vector<Variable> vars;
    string cname;
    bool h;
public:
    explicit Constructor(const std::vector<Variable>& _v,bool _h = false,cstr _n = "");
    string make(int t);
    string makeF(int t);
private:
    string null(cstr t);
    string classC(bool a);
};

#endif
