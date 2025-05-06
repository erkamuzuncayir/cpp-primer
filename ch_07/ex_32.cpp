//
// Created by erkam on 05/05/25.
//

#include <iostream>

class Window_mgr
{
public:
    void clear();
};

void Window_mgr::clear()
{
    std::cout << "Cleared!\n";
}

class Screen
{
    friend void Window_mgr::clear();
};

int main(void)
{
    Window_mgr my_mngr;
    my_mngr.clear();

    return 0;
}
