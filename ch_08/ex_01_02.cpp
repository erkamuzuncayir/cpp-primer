//
// Created by erkam on 07/05/25.
//

#include <iostream>
#include <string>

using std::istream;
using std::string;
using std::cout;
using std::endl;

istream& read(istream& stream) 
{
    string input;	
	while (stream >> input)
        cout << input << endl;

    stream.clear();

    return stream;
}

int main(void) { read(std::cin); }
