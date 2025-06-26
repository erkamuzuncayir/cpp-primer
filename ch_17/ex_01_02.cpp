// -----------------------------------------------------------------------------
// File:        ex_01_02.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <string>
#include <tuple>
#include <vector>

int main()
{
    std::tuple<int, int, int>                                                      nums              = {10, 20, 30};
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> complicated_tuple = {
        std::string("hey"), std::vector<std::string>({"hello", "world"}), std::make_pair(std::string("hello"), 2)};
}
