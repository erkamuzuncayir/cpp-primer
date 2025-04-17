//
// Created by erkam on 4/17/25.
//

#ifndef EX_44_H
#define EX_44_H
#include <string>
using std::string;

// Both declaration and definition must be in header.
inline bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}
#endif //EX_44_H
