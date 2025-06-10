// -----------------------------------------------------------------------------
// File:        ex_13.cpp
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
    pairs.push_back(std::make_pair("t", 1)); // This is the most readable.
    std::pair<string, int> temp_1("te", 2);
    std::pair<string, int> temp_2 = {"tes", 3};
}
