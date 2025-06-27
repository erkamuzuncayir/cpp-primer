/***************************************************************************
 *  @file       ex_06_07_08.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>
#include <typeinfo>

struct Query_base
{
    virtual ~Query_base()           = default;
    virtual std::string rep() const = 0;
};

struct AndQuery : public Query_base
{
    std::string rep() const override { return "AndQuery"; }
};

struct OrQuery : public Query_base
{
    std::string rep() const override { return "OrQuery"; }
};

// ex_06
void test_pointer_cast(Query_base *qb)
{
    std::cout << "[Pointer Cast Test] ";
    if (AndQuery *aq = dynamic_cast<AndQuery *>(qb))
    {
        std::cout << "✅ Cast to AndQuery* succeeded: " << aq->rep() << "\n";
    }
    else
    {
        std::cout << "❌ Cast to AndQuery* failed\n";
    }
}

// ex_07
void test_reference_cast(Query_base &qb)
{
    std::cout << "[Reference Cast Test] ";
    try
    {
        AndQuery &aq = dynamic_cast<AndQuery &>(qb);
        std::cout << "✅ Reference cast succeeded: " << aq.rep() << "\n";
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "❌ Reference cast failed: " << e.what() << "\n";
    }
}

// ex_08
void test_typeid(Query_base *q1, Query_base *q2)
{
    std::cout << "[typeid Test] ";
    if (typeid(*q1) == typeid(*q2))
    {
        std::cout << "Both are of type: " << typeid(*q1).name() << "\n";
    }
    else
    {
        std::cout << "Different types: " << typeid(*q1).name() << " vs " << typeid(*q2).name() << "\n";
    }

    if (typeid(*q1) == typeid(AndQuery))
    {
        std::cout << "q1 is an AndQuery ✅\n";
    }
    else
    {
        std::cout << "q1 is NOT an AndQuery ❌\n";
    }
}

int main()
{
    AndQuery aq;
    OrQuery  oq;

    Query_base *pa = &aq;
    Query_base *po = &oq;

    std::cout << "=== Testing with AndQuery ===\n";
    test_pointer_cast(pa);
    test_reference_cast(*pa);
    test_typeid(pa, pa);

    std::cout << "\n=== Testing with OrQuery ===\n";
    test_pointer_cast(po);
    test_reference_cast(*po);
    test_typeid(pa, po);

    return 0;
}
