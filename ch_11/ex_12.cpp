// -----------------------------------------------------------------------------
// File:        ex_12.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <string>
#include <utility>
#include <vector>

using std::string;


int main(void)
{
    std::vector<std::pair<string, int>> pairs;
    pairs.push_back(std::make_pair("t", 1));
    pairs.push_back(std::make_pair("te", 2));
    pairs.push_back(std::make_pair("tes", 3));
    pairs.push_back(std::make_pair("test", 4));
}
