// -----------------------------------------------------------------------------
// File:        ex_28_29_30.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <random>

unsigned rand_num()
{
    static std::default_random_engine              e;
    static std::uniform_int_distribution<unsigned> u;

    return u(e);
}

unsigned rand_num(unsigned seed)
{
    static std::default_random_engine              e(seed);
    static std::uniform_int_distribution<unsigned> u;

    return u(e);
}

unsigned rand_num(size_t min, size_t max)
{
    static std::default_random_engine              e;
    static std::uniform_int_distribution<unsigned> u(min, max);

    return u(e);
}

int main()
{
    std::cout << "Random numbers with default range:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << rand_num() << "\n";

    std::cout << "\nRandom numbers with seed 42:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << rand_num(42) << "\n";

    std::cout << "\nRandom numbers in [100, 200] with no seed (true random):\n";
    for (int i = 0; i < 5; ++i)
        std::cout << rand_num(100, 200) << "\n";
}
