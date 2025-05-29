// -----------------------------------------------------------------------------
// File:        ex_33.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::ifstream              in("../input.txt");
    std::ofstream              file_odd("../output_1.txt"), file_even("../output_2.txt");
    std::istream_iterator<int> int_it(in), eof;
    std::ostream_iterator<int> out_odd(file_odd), out_even(file_even);
    std::vector<int>           odd, even;

    if (!in)
    {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }


    while (int_it != eof)
    {
        int temp = *int_it++;
        temp % 2 == 0 ? even.push_back(temp) : odd.push_back(temp);
    }

    std::copy(odd.cbegin(), odd.cend(), out_odd);
    std::copy(even.cbegin(), even.cend(), out_even);

    return 0;
}
