// -----------------------------------------------------------------------------
// File:        ex_21_22.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template <typename T>
    void operator()(T *p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream &os;
};


class QueryResult;

class TextQuery
{
public:
    explicit TextQuery(std::ifstream &in_file)
    {
        get_input(in_file);
        build_map();
    };
    void                                get_input(std::ifstream &in_file);
    void                                build_map();
    QueryResult query(std::string &query_word);

private:
    std::vector<std::string>                                   lines;
    std::map<std::string, std::shared_ptr<std::set<unsigned>>> word_line_map;
};

class QueryResult
{
public:
    explicit QueryResult(std::string &search_word, std::shared_ptr<std::set<unsigned>> set) : word(search_word), word_set(set){};
    void print();

private:
    std::string                         word;
    std::shared_ptr<std::set<unsigned>> word_set;
};

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
                ptr = std::shared_ptr<std::set<unsigned>>(new std::set<unsigned>, DebugDelete());
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
    return QueryResult(query_word, std::shared_ptr<std::set<unsigned>>(new std::set<unsigned>, DebugDelete()));
}

void QueryResult::print()
{
    for (auto l : *word_set)
        std::cout << l << " ";
    std::cout << std::endl;
}

int main()
{
    std::ifstream in("***/input.txt");
    TextQuery     text_query(in);
    std::string   query_word("Donec");
    QueryResult   result = text_query.query(query_word);
    result.print();
}
