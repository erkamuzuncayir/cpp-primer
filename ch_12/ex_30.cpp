// -----------------------------------------------------------------------------
// File:        ex_30.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include "ex_30.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

void TextQuery::get_input(std::ifstream &in_file)
{
    std::string line;
    while (getline(in_file, line))
        lines.push_back(line);
}

void TextQuery::build_map()
{
    int line_num = 0;
    for (auto &line : lines)
    {
        std::istringstream line_stream(line);
        std::string        word;
        while (line_stream >> word)
        {
            auto &ptr = word_line_map[word];
            if (ptr == nullptr)
                ptr = std::make_shared<std::set<unsigned>>();
            ptr->insert(line_num);
        }
        ++line_num;
    }
}

QueryResult TextQuery::query(std::string &query_word)
{
    auto it = word_line_map.find(query_word);
    if (it != word_line_map.end())
        return QueryResult(query_word, it->second);
    return QueryResult(query_word, std::make_shared<std::set<unsigned>>());
}

void QueryResult::print()
{
    for (auto l : *word_set)
        std::cout << l << " ";
    std::cout << std::endl;
}

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        auto result = tq.query(s);
        result.print();
    }
}

int main()
{
    std::ifstream in("***/input.txt");
    runQueries(in);
}
