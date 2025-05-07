//
// Created by erkam on 07/05/25.
//

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::string;

istream &read(istream &stream)
{
    string word, line;
    while (getline(stream, line))
    {
        istringstream sin(line);
        while (sin >> word)
            cout << word << endl;
    }

    stream.clear();

    return stream;
}

int main(void) { read(std::cin); }
