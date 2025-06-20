// -----------------------------------------------------------------------------
// File:        ex_30.cpp
// Author:      Erkam Uzuncayir
// Date:        20/06/2025
// -----------------------------------------------------------------------------

#include <__msvc_ostream.hpp>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

    Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {}
    Quote(Quote &&rhs) : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {}
    Quote &operator=(const Quote &rhs)
    {
        if (this != &rhs)
        {
            bookNo = rhs.bookNo;
            price  = rhs.price;
        }
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        if (this != &rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price  = std::move(rhs.price);
        }
        return *this;
    }

    std::string    isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    // virtual void   debug();

    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc)
    {
    }
    double      net_price(std::size_t) const = 0;
    std::size_t get_qty() const { return quantity; }

protected:
    std::size_t quantity = 0;
    double      discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;
    Bulk_quote() { std::cout << "Bulk_quote constructor" << std::endl; };
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs), min_qty(rhs.min_qty) {}
    Bulk_quote(Bulk_quote &&rhs) : Disc_quote(std::move(rhs)), min_qty(std::move(rhs.min_qty)) {}
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Disc_quote::operator=(rhs);
        if (this != &rhs)
        {
            min_qty  = rhs.min_qty;
            discount = rhs.discount;
        }
        return *this;
    }
    Bulk_quote &operator=(Bulk_quote &&rhs)
    {
        Disc_quote::operator=(std::move(rhs));
        if (this != &rhs)
        {
            min_qty  = std::move(rhs.min_qty);
            discount = std::move(rhs.discount);
        }
        return *this;
    }

    Bulk_quote *clone() const & { return new Bulk_quote(*this); }
    Bulk_quote *clone() && { return new Bulk_quote(std::move(*this)); }

    double net_price(std::size_t) const override;

private:
    std::size_t min_qty = 0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;

    return cnt * price;
}

class Basket
{
public:
    void   add_item(const Quote &sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void   add_item(Quote &&sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
    double total_receipt(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}

int main()
{
    Basket     basket;
    Bulk_quote b_q_1("1111", 120.0, 15, 0.3);
    Bulk_quote b_q_2("2222", 250.0, 15, 0.2);
    Bulk_quote b_q_3("3333", 350.0, 15, 1);
    basket.add_item(b_q_1);
    basket.add_item(b_q_2);
    basket.add_item(b_q_3);

    basket.total_receipt(std::cout);
    return 0;
}
