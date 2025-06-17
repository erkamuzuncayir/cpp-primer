// -----------------------------------------------------------------------------
// File:        ex_18.cpp
// Author:      Erkam Uzuncayir
// Date:        15/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

class Employee
{
public:
    using employee_id = unsigned;
    Employee(std::string n)
    {
        name = n;
        id   = unique_id;
        ++unique_id;
    };
    const std::string &get_name() const { return name; }
    employee_id        get_id() const { return id; }
    static employee_id unique_id;

private:
    std::string name;
    employee_id id;
};

Employee::employee_id Employee::unique_id = 0;

void print(const Employee &e) { std::cout << e.get_id() << " " << e.get_name() << std::endl; };

int main()
{
    Employee a("George"), b("Steven"), c("Ron");
    print(a);
    print(b);
    print(c);
}
