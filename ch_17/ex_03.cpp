// -----------------------------------------------------------------------------
// File:        ex_03.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using LineNums = std::shared_ptr<std::set<unsigned>>;
using QueryResult = std::tuple<std::string, LineNums>;

class TextQuery {
public:
    explicit TextQuery(std::ifstream &in) : file(in) {
        read_input();
        build_index();
    }

    QueryResult query(const std::string &word) const {
        auto it = index.find(word);
        if (it != index.end())
            return { word, it->second };

        return { word, std::make_shared<std::set<unsigned>>() };
    }

private:
    void read_input() {
        std::string line;
        while (std::getline(file, line))
            lines.push_back(line);
    }

    void build_index() {
        for (unsigned ln = 0; ln < lines.size(); ++ln) {
            std::istringstream stream(lines[ln]);
            std::string w;
            while (stream >> w) {
                auto &ptr = index[w];
                if (!ptr)
                    ptr = std::make_shared<std::set<unsigned>>();
                ptr->insert(ln);
            }
        }
    }

    std::ifstream                        &file;
    std::vector<std::string>              lines;
    std::map<std::string, LineNums>       index;
};

void run_queries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;

        auto [word, lines] = tq.query(s);
        std::cout << "'" << word << "' occurs on line(s): ";
        for (auto ln : *lines) std::cout << ln << " ";
        std::cout << "\n\n";
    }
}

int main() {
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "couldn't open input.txt\n";
        return 1;
    }
    run_queries(infile);
    return 0;
}
