// -----------------------------------------------------------------------------
// File:        ex_17.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Sales_data
{
public:
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n) {}
    std::string isbn() const { return book_no; }

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

bool compare_isbn(const Sales_data &s1, const Sales_data &s2) { return s1.isbn() < s2.isbn(); }

int main(void)
{
    std::vector<Sales_data> data;
    data.push_back(Sales_data("123", 1, 2));
    data.push_back(Sales_data("1433", 1, 2));
    data.push_back(Sales_data("152223", 1, 2));
    data.push_back(Sales_data("1333", 1, 2));
    data.push_back(Sales_data("123", 1, 2));

    for (auto d : data)
        std::cout << d.isbn() << ' ';
    std::cout << std::endl;

    std::stable_sort(data.begin(), data.end(),
                     [](const Sales_data &s1, const Sales_data &s2) { return s1.isbn() < s2.isbn(); });

    for (auto d : data)
        std::cout << d.isbn() << ' ';

    return 0;
}
