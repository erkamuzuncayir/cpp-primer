//
// Created by erkam on 05/05/25.
//

#include <string>

class Vehicle
{
public:
    Vehicle() : Vehicle(0.0, 0.0, "") {}
    Vehicle(double sp = 0.0, double vel = 0.0) : Vehicle(sp, vel, "") {}
    Vehicle(double sp, double vel, std::string lp) : speed(sp), velocity(vel), license_plate(lp) {}
private:
    double speed;
    double velocity;
    std::string license_plate;
};
