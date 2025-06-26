// -----------------------------------------------------------------------------
// File:        ex_33.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>

using namespace std;

map<string, vector<string>> buildMap(const vector<string> &lines)
{
    map<string, vector<string>> trans_map;

    for (const auto &line : lines) {
        istringstream iss(line);
        string key, word;
        if (iss >> key) {
            vector<string> replacements;
            while (iss >> word)
                replacements.push_back(word);

            if (!replacements.empty())
                trans_map[key] = replacements;
        }
    }

    return trans_map;
}

string transform(const string &word, const map<string, vector<string>> &trans_map)
{
    static std::uniform_int_distribution<unsigned> u;
    static default_random_engine engine{random_device{}()};

    auto it = trans_map.find(word);
    if (it != trans_map.end()) {
        const auto &options = it->second;
        uniform_int_distribution<size_t> dist(0, options.size() - 1);
        return options[dist(engine)];
    } else {
        return word; // dönüşüm yoksa kelimeyi aynen döndür
    }
}

void word_transform(const vector<string> &map_lines, const vector<string> &input_lines)
{
    auto trans_map = buildMap(map_lines);

    for (const auto &line : input_lines) {
        istringstream stream(line);
        string word;
        bool firstword = true;

        while (stream >> word) {
            if (!firstword)
                cout << " ";
            else
                firstword = false;

            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

// main içinde test örneği
int main()
{
    vector<string> map_lines = {
        "hello hi hey yo",
        "world earth globe planet",
        "test exam quiz trial"
    };

    vector<string> input_lines = {
        "hello world this is a test",
        "test your hello skills"
    };

    cout << "Random Word Transformation Output:\n";
    word_transform(map_lines, input_lines);

    return 0;
}
