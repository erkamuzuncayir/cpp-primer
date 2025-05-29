// -----------------------------------------------------------------------------
// File:        ex_32.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include "C:\Repository\StudyRepositories\cpp-primer\ch_01\Sales_item.h"

bool compare_isbn(const Sales_item &item1, const Sales_item &item2) { return item1.isbn() < item2.isbn(); }

int main()
{
    std::istream_iterator<Sales_item> item_it(std::cin), eof;
    std::vector<Sales_item>           items(item_it, eof);
    std::sort(items.begin(), items.end(), compare_isbn);

    std::vector<Sales_item>::iterator end;
    for (auto it = items.begin(), end = it; it != items.end(); ++it)
    {
        end = std::find_if(it, items.end(), [it](const Sales_item &other) { return it->isbn() != other.isbn(); });
        std::cout << std::accumulate(it, end, Sales_item(it->isbn())) << std::endl;
    }
    return 0;
}
