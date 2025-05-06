//
// Created by erkam on 06/05/25.
//

#include <iostream>
#include <string>

class Person
{
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);
public:
    Person() = default;
    Person(const std::string &n) : name(n) {}
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}
    explicit Person(std::istream &);
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.address;
    return os;
}
