// -----------------------------------------------------------------------------
// File:        ex_42.h
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_42_H
#define EX_42_H

#include <fstream>
#include <map>
#include <set>
#include <vector>

#include "ex_39_40.h"

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
    StrVec                                   lines;
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
#endif //EX_42_H
