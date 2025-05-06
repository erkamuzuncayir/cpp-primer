//
// Created by erkam on 05/05/25.
//

#include <iostream>
#include <string>

class Screen
{
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd) : heigth(ht), width(wd), contents(ht * wd, ' '){}
    Screen(pos ht, pos wd, char c) : heigth(ht), width(wd), contents(ht * wd, c){}
    char get() const { return contents[cursor];}
    char get(pos ht, pos wd) const { return contents[ht * wd];}
    Screen &move(pos row, pos col);
private:
    pos heigth = 0;
    pos width = 0;
    pos cursor = 0;
    std::string contents;
};

inline Screen &Screen::move(pos row, pos col)
{
    cursor = row * width + col;
    return *this;
}
