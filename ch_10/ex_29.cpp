// -----------------------------------------------------------------------------
// File:        ex_29.cpp
// Author:      Erkam Uzuncayir
// Date:        28/05/2025
// -----------------------------------------------------------------------------


#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::istream_iterator;
using std::string;

int main()
{
    std::vector<string>      words;
    std::ifstream in("***/input.txt");
    istream_iterator<string> str_it(in);
    istream_iterator<string> eof;

    if (!in)
    {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    while (str_it != eof)
        words.push_back(*str_it++);

    for (auto w : words)
        std::cout << w << ' ';


    return 0;
}
