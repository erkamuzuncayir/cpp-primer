// -----------------------------------------------------------------------------
// File:        ex_49.cpp
// Author:      Erkam Uzuncayir
// Date:        10/05/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

string find_longest_non_ascender_nor_descender(vector<string> &vec_str)
{
    string   ascender_and_descender_letters{"bdfhkltgjpqy"};
    unsigned longest_word_size = 0;
    string   longest_word;
    auto     it = vec_str.cbegin();

    while (it != vec_str.cend())
    {
        if ((*it).find_first_of(ascender_and_descender_letters, 0) == string::npos)
        {
            if ((*it).size() > longest_word_size)
            {
                longest_word_size = (*it).size();
                longest_word      = *it;
            }
        }
        it++;
    }

    return longest_word;
}

void read(const string &file_name, vector<string> &vec_str)
{
    ifstream in(file_name);

    if (in)
    {
        string temp;
        while (in >> temp)
            vec_str.push_back(temp);
    }
}

int main(int argc, char *argv[])
{
    vector<string> vec_str;
    read(argv[1], vec_str);

    cout << '\n' << find_longest_non_ascender_nor_descender(vec_str);
}
