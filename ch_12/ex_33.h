// -----------------------------------------------------------------------------
// File:        ex_33.h
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_32_H
#define EX_32_H

#include "ex_19.h"
#include <fstream>
#include <map>
#include <set>

class QueryResult;

class TextQuery
{
public:
    explicit TextQuery(std::ifstream &in_file) : file(in_file)
    {
        get_input(in_file);
        build_map();
    };
    void                                get_input(std::ifstream &in_file);
    void                                build_map();
    QueryResult query(std::string &query_word);

private:
    std::ifstream                                             &file;
    StrBlob                                   lines;
    std::map<std::string, std::shared_ptr<std::set<unsigned>>> word_line_map;
};

class QueryResult
{
public:
    explicit QueryResult(std::string &search_word, std::shared_ptr<std::set<unsigned>> set) : word(search_word), word_set(set){};
    void print();

    std::set<unsigned>::iterator begin() { return word_set->begin(); }
    std::set<unsigned>::iterator end() { return word_set->end(); }

    std::shared_ptr<std::set<unsigned>> get_file() { return word_set; }
private:
    std::string                         word;
    std::shared_ptr<std::set<unsigned>> word_set;
};

#endif //EX_32_H
