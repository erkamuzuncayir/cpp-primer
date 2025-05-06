//
// Created by erkam on 05/05/25.
//

#include <string>

typedef std::string Type;
Type initVal(); // Type at line 7
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // Type at line 11
    Type initVal(); // Type at line 11
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm) {  // Type at line 11 and this cause an error. We can add `Exercise::` at the beginning of `Type` in line 18.
    val = parm + initVal();
    return val;
}
