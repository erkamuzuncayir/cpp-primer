// -----------------------------------------------------------------------------
// File:        ex_33.cpp
// Author:      Erkam Uzuncayir
// Date:        10/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using std::ifstream;
using std::string;

std::map<string, string> build_map(ifstream& map_file)
{
    std::map<string, string> trans_map;
    string                   key, value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
    return trans_map;
}

const string& transform(const string& s, const std::map<string, string>& m)
{
    const auto map_it = m.find(s);
    return map_it == m.cend() ? s : map_it->second;
}

void word_transform(ifstream& map, ifstream& input)
{
    auto   trans_map = build_map(map);
    string text;
    while (getline(input, text))
    {
        std::istringstream iss(text);
        for (string word; iss >> word;)
            std::cout << transform(word, trans_map) << " ";
        std::cout << std::endl;
    }
}

int main()
{
    ifstream input_file("../input.txt"), transform_words_file("../transform_words.txt");
    if (input_file && transform_words_file)
        word_transform(transform_words_file, input_file);
    else
        std::cerr << "can't find the documents." << std::endl;
}
