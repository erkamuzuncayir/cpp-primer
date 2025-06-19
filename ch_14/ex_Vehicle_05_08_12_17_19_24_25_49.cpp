// -----------------------------------------------------------------------------
// File:        ex_Vehicle_05_08_12_17_19_24_25_49.cpp
// Author:      Erkam Uzuncayir
// Date:        18/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <utility>

class Vehicle
{
    friend std::istream &operator>>(std::istream &is, Vehicle &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);
    friend bool          operator==(const Vehicle &lhs, const Vehicle &rhs);
    friend bool          operator<(const Vehicle &lhs, const Vehicle &rhs);

public:
    Vehicle() : speed(0), velocity(0) {}
    Vehicle(double sp, double vel, std::string lp) : speed(sp), velocity(vel), license_plate(std::move(lp)) {}

    Vehicle &operator=(const Vehicle &rhs);
    Vehicle &operator=(std::string new_license_plate);
    Vehicle &operator=(Vehicle &&rhs);

    explicit operator bool() const { return speed > 0; }

private:
    double      speed;
    double      velocity;
    std::string license_plate;
};

Vehicle &Vehicle::operator=(const Vehicle &rhs)
{
    if (this != &rhs)
    {
        speed         = rhs.speed;
        velocity      = rhs.velocity;
        license_plate = rhs.license_plate;
    }
    return *this;
}

// With this overload, user can set new license plate for vehicle.
Vehicle &Vehicle::operator=(std::string new_license_plate)
{
    license_plate = std::move(new_license_plate);
    return *this;
}

Vehicle &Vehicle::operator=(Vehicle &&rhs)
{
    if (this != &rhs)
    {
        speed         = rhs.speed;
        velocity      = rhs.velocity;
        license_plate = std::move(rhs.license_plate);
    }
    return *this;
}

bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
    return lhs.license_plate == rhs.license_plate && lhs.speed == rhs.speed && lhs.velocity == rhs.velocity;
}

bool operator!=(const Vehicle &lhs, const Vehicle &rhs) { return !(lhs == rhs); }

bool operator<(const Vehicle &lhs, const Vehicle &rhs) { return lhs.speed < rhs.speed; }

bool operator>(const Vehicle &lhs, const Vehicle &rhs) { return rhs < lhs; }

std::istream &operator>>(std::istream &is, Vehicle &rhs)
{
    if (is)
        is >> rhs.speed >> rhs.velocity >> rhs.license_plate;
    else
        rhs = Vehicle();
    return is;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle)
{
    os << vehicle.speed << " " << vehicle.velocity << " " << vehicle.license_plate;
    return os;
}

int main()
{
    Vehicle v1, v2;
    std::cout << "Vehicle 1: ";
    std::cin >> v1;
    std::cout << "Vehicle 2: ";
    std::cin >> v2;
    std::cout << v1 << v2 << std::endl;
    std::cout << "Does v1 and v2 is the same vehicle: " << ((v1 == v2) ? "Yes" : "No") << std::endl;
    std::cout << "Does v1 is faster than v2: " << ((v1 < v2) ? "Yes" : "No") << std::endl;
}
