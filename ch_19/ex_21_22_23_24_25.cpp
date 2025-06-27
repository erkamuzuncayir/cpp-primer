/***************************************************************************
 *  @file       ex_21_22_23_24_25.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

// It is to assign a Token object to itself safe due to the self-assignment
// check in the copy/move assignment operators (i.e., if (this != &t)).
// If you skip that check and tok == STR, you may call sval.~string()
// before copying, causing undefined behavior if t is the same object.

#include <string>
using std::string;

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

class Token
{
public:
    Token() : tok(INT), ival(0) {}
    Token(const Token &t) : tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token &);
    ~Token();

    Token &operator=(const std::string &);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    Token &operator=(const Sales_data &);
    Token(Token &&t) noexcept;
    Token &operator=(Token &&t) noexcept;

private:
    enum
    {
        INT,
        CHAR,
        DBL,
        STR,
        SALES
    } tok;

    union
    {
        char        cval;
        int         ival;
        double      dval;
        std::string sval;
        Sales_data  sdval;
    };

    void copyUnion(const Token &);
};

Token::Token(Token &&t) noexcept : tok(t.tok)
{
    switch (tok)
    {
        case INT:
            ival = t.ival;
            break;
        case CHAR:
            cval = t.cval;
            break;
        case DBL:
            dval = t.dval;
            break;
        case STR:
            new (&sval) std::string(std::move(t.sval));
            break;
        case SALES:
            new (&sdval) Sales_data(std::move(t.sdval));
            break;
    }
}

Token &Token::operator=(Token &&t) noexcept
{
    if (this != &t)
    {
        if (tok == STR)
            sval.~string();
        else if (tok == SALES)
            sdval.~Sales_data();

        tok = t.tok;
        switch (tok)
        {
            case INT:
                ival = t.ival;
                break;
            case CHAR:
                cval = t.cval;
                break;
            case DBL:
                dval = t.dval;
                break;
            case STR:
                new (&sval) std::string(std::move(t.sval));
                break;
            case SALES:
                new (&sdval) Sales_data(std::move(t.sdval));
                break;
        }
    }
    return *this;
}

Token &Token::operator=(char c)
{
    if (tok == STR)
        sval.~string();
    else if (tok == SALES)
        sdval.~Sales_data();
    cval = c;
    tok  = CHAR;
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == STR)
        sval.~string();
    else if (tok == SALES)
        sdval.~Sales_data();
    dval = d;
    tok  = DBL;
    return *this;
}

Token &Token::operator=(const Sales_data &s)
{
    if (tok == SALES)
        sdval = s;
    else
    {
        if (tok == STR)
            sval.~string();
        new (&sdval) Sales_data(s);
        tok = SALES;
    }
    return *this;
}
