// -----------------------------------------------------------------------------
// File:        ex_28.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream                             in_file("***/input.txt");
    std::vector<std::string>                  lines;
    std::map<std::string, std::set<unsigned>> word_line_map;

    std::string temp;
    while (std::getline(in_file, temp))
        lines.push_back(temp);

    int line_num = 0;
    for (auto &line : lines)
    {
        std::istringstream line_stream(line);
        std::string        word;
        while (line_stream >> word)
        {
            auto &ptr = word_line_map[word];
            ptr.insert(line_num);
        }
        ++line_num;
    }

    std::string query_word = "Donec";
    auto        it         = word_line_map.find(query_word);
    if (it != word_line_map.end())
    {
        for (auto &line_num_ptr : it->second)
            std::cout << line_num_ptr << std::endl;
    }
    else
        std::cout << "Not found" << std::endl;
}
