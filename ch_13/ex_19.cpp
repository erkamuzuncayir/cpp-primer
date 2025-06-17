// -----------------------------------------------------------------------------
// File:        ex_19.cpp
// Author:      Erkam Uzuncayir
// Date:        15/06/2025
// -----------------------------------------------------------------------------

// There is no sensible meaning to copy an employee. So it deletes copy-control.

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
    Employee(const Employee &e)                     = delete;
    Employee          &operator=(const Employee &e) = delete;
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
    Employee a("George"), b("Steven"), c = b;
    print(a);
    print(b);
    print(c);
}
