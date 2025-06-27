/***************************************************************************
 *  @file       ex_20.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class TextQuery
{
public:
    // Nested QueryResult class
    class QueryResult
    {
    public:
        QueryResult(const std::string &search_word, std::shared_ptr<std::set<unsigned>> set) :
            word(search_word), word_set(std::move(set))
        {
        }

        void print() const
        {
            for (unsigned line : *word_set)
                std::cout << line << " ";
            std::cout << std::endl;
        }

    private:
        std::string                         word;
        std::shared_ptr<std::set<unsigned>> word_set;
    };

    explicit TextQuery(std::ifstream &in_file)
    {
        get_input(in_file);
        build_map();
    }

    QueryResult query(const std::string &query_word)
    {
        auto it = word_line_map.find(query_word);
        if (it != word_line_map.end())
            return QueryResult(query_word, it->second);
        return QueryResult(query_word, std::make_shared<std::set<unsigned>>());
    }

private:
    void get_input(std::ifstream &in_file)
    {
        std::string line;
        while (getline(in_file, line))
            lines.push_back(line);
    }

    void build_map()
    {
        int line_num = 0;
        for (auto &line : lines)
        {
            std::istringstream line_stream(line);
            std::string        word;
            while (line_stream >> word)
            {
                auto &ptr = word_line_map[word];
                if (!ptr)
                    ptr = std::make_shared<std::set<unsigned>>();
                ptr->insert(line_num);
            }
            ++line_num;
        }
    }

    std::vector<std::string>                                   lines;
    std::map<std::string, std::shared_ptr<std::set<unsigned>>> word_line_map;
};

int main()
{
    std::ifstream in("input.txt"); // replace with actual path
    if (!in)
    {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    TextQuery   text_query(in);
    std::string query_word("Donec");

    TextQuery::QueryResult result = text_query.query(query_word);
    result.print();

    return 0;
}
