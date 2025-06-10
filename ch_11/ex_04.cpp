// -----------------------------------------------------------------------------
// File:        ex_04.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <set>
#include <string>

using std::string;

string get_word(string &input_word)
{
    std::set<char> punctuations{'\\', '"', ':', '*', '-', '_', ';', ',', '.', '?', '!', '(', ')', '[', ']', '{', '}'};

    string output;
    for (char &c : input_word)
    {
        if (punctuations.find(c) == punctuations.end())
        {
            if (c >= 'A' && c <= 'Z')
                c -= 'A' - 'a';

            output.push_back(c);
        }
    }
    return output;
}

int main(void)
{
    std::map<string, size_t> word_count_map;
    string                   word;

    while (std::cin >> word)
        ++word_count_map[get_word(word)];

    for (const auto &w : word_count_map)
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << '\n';
}
