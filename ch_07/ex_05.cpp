//
// Created by erkam on 4/18/25.
//

#include <string>

struct Person
{
    std::string get_name() const { return name; }       // Both of them should const,
    std::string get_address() const { return address; } // they won't change data inside class
    std::string name;                                   // they just return information.
    std::string address;
};
