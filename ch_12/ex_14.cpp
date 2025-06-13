// -----------------------------------------------------------------------------
// File:        ex_14.cpp
// Author:      Erkam Uzuncayir
// Date:        11/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <string>

struct destination
{
    std::string name;
    std::string address;
    destination(std::string name, std::string address) : name(name), address(address) {}
};

struct connection
{
    destination *dest;
    explicit connection(destination *dest) : dest(dest) {}
};

void disconnect(connection *con)
{
    std::cout << "Disconnecting from " << con->dest->name << " which address is: " << con->dest->address << std::endl;
}

void end_connection(connection *con) { disconnect(con); }

std::shared_ptr<connection> connect(destination *dest)
{
    std::shared_ptr<connection> newCon(new connection(dest), end_connection);
    std::cout << "Connecting to " << newCon->dest->name << " which address is: " << newCon->dest->address << std::endl;
    return newCon;
}

int main()
{
    destination                 dest("Work", "192.168.0.0");
    std::shared_ptr<connection> con_ptr = connect(&dest);
}
