//
// Created by erkam on 4/16/25.
//

#include <iostream>
using std::string;

int main(int argc, char** argv)
{
    string s;
    for (int i = 1; i < argc; i++)
    {
        s += argv[i];
        s += ' ';
    }
    
    std::cout << s << std::endl;
}
