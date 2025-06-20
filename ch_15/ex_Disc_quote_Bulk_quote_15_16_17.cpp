// -----------------------------------------------------------------------------
// File:        ex_Disc_quote_Bulk_quote_15_16_17.cpp
// Author:      Erkam Uzuncayir
// Date:        20/06/2025
// -----------------------------------------------------------------------------


#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string    isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void   debug();
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

protected:
    std::size_t quantity = 0;
    double      discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
    }
    double net_price(std::size_t) const override;

private:
    std::size_t min_qty  = 0;
    double      discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main()
{
    // error C2259: 'Disc_quote': cannot instantiate abstract class
    Disc_quote disc_quote("test", 1, 2, 0.4);
}
