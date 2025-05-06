//
// Created by erkam on 05/05/25.
//

#include <string>

class Vehicle
{
public:
    Vehicle() : speed(0.0), velocity(0.0), license_plate("") {}
    Vehicle(double sp = 0.0, double vel = 0.0) : speed(sp), velocity(vel){}
    Vehicle(double sp, double vel, std::string lp) : speed(sp), velocity(vel), license_plate(lp) {}
private:
    double speed;
    double velocity;
    std::string license_plate;
};
