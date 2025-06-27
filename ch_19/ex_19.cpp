/***************************************************************************
 *  @file       ex_19.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Sales_data
{
public:
    Sales_data(std::string s, unsigned n, double p) : book_no(std::move(s)), units_sold(n), revenue(n * p) {}

    double avg_price() const { return units_sold ? revenue / units_sold : 0; }

    void print() const { std::cout << "Book: " << book_no << ", Avg Price: " << avg_price() << "\n"; }

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

void find_pricey_book(const std::vector<Sales_data> &books, double min_price)
{
    // pointer to member function
    auto avg_fn = &Sales_data::avg_price;

    auto it = std::find_if(books.begin(), books.end(),
                           [avg_fn, min_price](const Sales_data &s) { return (s.*avg_fn)() > min_price; });

    if (it != books.end())
    {
        std::cout << "First book with avg_price > " << min_price << ":\n";
        it->print();
    }
    else
    {
        std::cout << "No book with avg_price > " << min_price << "\n";
    }
}

int main()
{
    std::vector<Sales_data> books = {{"111-AAA", 10, 3.0}, {"222-BBB", 5, 10.0}, {"333-CCC", 0, 0.0}};

    find_pricey_book(books, 5.5); // should match second book
}
