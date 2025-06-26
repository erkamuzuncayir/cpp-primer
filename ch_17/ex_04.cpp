// -----------------------------------------------------------------------------
// File:        ex_04.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

class Sales_item;
class Sales_data
{
    friend std::istream &operator>>(std::istream &is, Sales_data &s);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend Sales_data    operator+(const Sales_data &, const Sales_data &);
    friend Sales_data    operator-(const Sales_data &, const Sales_data &);

public:
    Sales_data() = default;
    Sales_data(std::string s, unsigned n, double p) : book_no(std::move(s)), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &string) : Sales_data(string, 0, 0) {}

    explicit    operator std::string() const { return book_no; }
    explicit    operator double() const { return revenue; }
    Sales_data &operator=(const std::string &new_isbn);
    Sales_data &operator+=(const Sales_data &rhs);
    Sales_data &operator-=(const Sales_data &rhs);

    std::string isbn() const { return book_no; }

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data result = lhs;
    result -= rhs;
    return result;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data &Sales_data::operator=(const std::string &new_isbn)
{
    book_no = new_isbn;
    return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

std::istream &operator>>(std::istream &is, Sales_data &s)
{
    double price;
    is >> s.book_no >> s.units_sold >> price;
    if (is)
        s.revenue = s.units_sold * price;
    else
        s = Sales_data();
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &s)
{
    os << s.book_no << " " << s.units_sold << " " << s.revenue;
    return os;
}

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() == rhs.isbn(); }

// ex_04

// typedef std::tuple<std::vector<Sales_data>::size_type,
// std::vector<Sales_data>::const_iterator,std::vector<Sales_data>::const_iterator> matches;

// std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
// {
//     std::vector<matches> ret;
//     for (auto it = files.cbegin(); it != files.cend(); ++it)
//     {
//         auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
//         if (found.first != found.second)
//             ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
//     }
//     return ret;
// }

// ex_05

// using matches_pair =
//     std::pair<std::size_t, std::pair<std::vector<Sales_data>::const_iterator,
//     std::vector<Sales_data>::const_iterator>>;

// std::vector<matches_pair> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
// {
//     std::vector<matches_pair> ret;
//     for (auto it = files.cbegin(); it != files.cend(); ++it)
//     {
//         auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
//         if (found.first != found.second)
//             ret.push_back(std::make_pair(it - files.cbegin(),
//                                std::make_pair(found.first, found.second)));;
//     }
//     return ret;
// }

// ex_06
struct matches_struct
{
    std::vector<Sales_data>::size_type      index{};
    std::vector<Sales_data>::const_iterator beg_it;
    std::vector<Sales_data>::const_iterator end_it;
};

std::vector<matches_struct> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
    std::vector<matches_struct> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
        {
            matches_struct temp;
            temp.index = static_cast<std::vector<Sales_data>::size_type>(it - files.cbegin());
            temp.beg_it = found.first;
            temp.end_it = found.second;
            ret.push_back(temp);
        }
    }
    return ret;
}

void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
    std::string s;
    while (in >> s)
    {
        auto trans = findBook(files, s);
        if (trans.empty())
        {
            std::cout << s << " not found in any stores" << std::endl;
            continue;
        }
        for (const auto &store : trans)
            os << "store " << std::get<0>(store)
               << " sales: " << accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s)) << std::endl;
    }
}


int main()
{
    using Store = std::vector<Sales_data>;

    std::vector<Store> stores = {{Sales_data("123", 2, 50.0), Sales_data("456", 1, 25.0), Sales_data("789", 4, 15.0)},
                                 {Sales_data("123", 3, 50.0), Sales_data("999", 1, 60.0)},
                                 {Sales_data("000", 5, 10.0)}};

    for (auto &store : stores)
        std::sort(store.begin(), store.end(),
                  [](const Sales_data &a, const Sales_data &b) { return a.isbn() < b.isbn(); });

    auto result = findBook(stores, "123");
    std::cout << "[findBook] Found in " << result.size() << " store(s)." << std::endl;
    for (const auto &match : result)
    {
        std::cout << " - Store " << std::get<0>(match) << " has "
                  << std::distance(std::get<1>(match), std::get<2>(match)) << " record(s) for ISBN 123." << std::endl;
    }

    std::istringstream input("123 789 000 111");
    std::ostringstream output;
    reportResults(input, output, stores);

    std::cout << "\n[reportResults] Output:\n" << output.str();

    return 0;
}
