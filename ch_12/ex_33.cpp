// -----------------------------------------------------------------------------
// File:        ex_33.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include "ex_32.h"
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
    for (StrBlobPtr ptr_beg(lines.begin()), ptr_end(lines.end()); ptr_beg.current_position() != ptr_end.current_position(); ptr_beg.incr())
    {
        std::istringstream line_stream(ptr_beg.deref());
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

int main()
{
    std::ifstream in("C:/Repository/StudyRepositories/cpp-primer/input.txt");
    TextQuery     text_query(in);
    std::string   query_word("Donec");
    QueryResult   result = text_query.query(query_word);
    result.print();
}
