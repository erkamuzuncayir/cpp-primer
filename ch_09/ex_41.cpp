// -----------------------------------------------------------------------------
// File:        ex_41.cpp
// Author:      Erkam Uzuncayir
// Date:        09/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<char> cv{'H', 'e', 'l', 'l', 'o'};
    std::string       str(cv.begin(), cv.end());
    
    std::cout << str;
    return 0;
}
