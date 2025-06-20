// -----------------------------------------------------------------------------
// File:        ex_26_27_28_29.cpp
// Author:      Erkam Uzuncayir
// Date:        20/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

    Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price)
    {
        std::cout << "Quote copy constructor" << std::endl;
    }
    Quote(Quote &&rhs) : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))
    {
        std::cout << "Quote move constructor" << std::endl;
    }
    Quote &operator=(const Quote &rhs)
    {
        if (this != &rhs)
        {
            bookNo = rhs.bookNo;
            price  = rhs.price;
        }
        std::cout << "Quote copy assignment" << std::endl;
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        if (this != &rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price  = std::move(rhs.price);
        }
        std::cout << "Quote move assignment" << std::endl;
        return *this;
    }

    std::string    isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    // virtual void   debug();
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
    double net_price(std::size_t) const = 0;
    std::size_t    get_qty() const { return quantity; }

protected:
    std::size_t quantity = 0;
    double      discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;
    Bulk_quote() { std::cout << "Bulk_quote constructor" << std::endl; };
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs), min_qty(rhs.min_qty)
    {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }
    Bulk_quote(Bulk_quote &&rhs) :
        Disc_quote(std::move(rhs)), min_qty(std::move(rhs.min_qty))
    {
        std::cout << "Bulk_quote move constructor" << std::endl;
    }
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Disc_quote::operator=(rhs);
        if (this != &rhs)
        {
            min_qty  = rhs.min_qty;
            discount = rhs.discount;
        }
        std::cout << "Bulk_quote copy assignment" << std::endl;
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
        std::cout << "Bulk_quote move assignment" << std::endl;
        return *this;
    }

    double net_price(std::size_t) const override;

private:
    std::size_t min_qty  = 0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;

    return cnt * price;
}

int main()
{
    // ex_26
    std::cout << "----- Quote Tests -----" << std::endl;

    Quote q1("12345", 50.0); // Normal constructor
    Quote q2 = q1;           // Copy constructor
    Quote q3;
    q3       = q1;            // Copy assignment
    Quote q4 = std::move(q1); // Move constructor
    Quote q5;
    q5 = std::move(q2); // Move assignment

    std::cout << "\n----- Bulk_quote Tests -----" << std::endl;

    Bulk_quote b1("67890", 100.0, 10, 0.2); // Base constructor from Disc_quote
    Bulk_quote b2 = b1;                     // Copy constructor
    Bulk_quote b3;
    b3            = b1;            // Copy assignment
    Bulk_quote b4 = std::move(b1); // Move constructor
    Bulk_quote b5;
    b5 = std::move(b2); // Move assignment

    std::cout << "\n----- Polymorphic Behavior -----" << std::endl;

    Quote *ptr = new Bulk_quote("99999", 120.0, 15, 0.3);
    std::cout << "Net price for 20 units: " << ptr->net_price(20) << std::endl;
    delete ptr;

    // ex_28
    std::vector<Quote> vec = {
        Bulk_quote("1111", 120.0, 15, 0.3),
        Bulk_quote("2222", 250.0, 15, 0.2),
        Bulk_quote("3333", 350.0, 15, 1),
    };

    double sum = 0;
    for (const auto& el : vec)
    {
        sum += el.net_price(15);
    }

    std::cout << "Total price: " << sum << std::endl;

    // ex_29
    // Because both of them has net_price function and price variable
    std::vector<std::shared_ptr<Quote>> ptr_vec = {
        std::make_shared<Bulk_quote>("1111", 120.0, 15, 0.3),
        std::make_shared<Bulk_quote>("2222", 250.0, 15, 0.2),
        std::make_shared<Bulk_quote>("3333", 350.0, 15, 1),
    };

    sum = 0;
    for (const auto& el : ptr_vec)
    {
        sum += el->net_price(15);
    }

    std::cout << "Total price: " << sum << std::endl;
    return 0;
}
