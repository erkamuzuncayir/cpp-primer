//
// Created by erkam on 05/05/25.
//

#include <iostream>
#include <string>
using std::cout;

class Screen
{
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd) : heigth(ht), width(wd), contents(ht * wd, ' '){}
    Screen(pos ht, pos wd, char c) : heigth(ht), width(wd), contents(ht * wd, c){}
    char get() const { return contents[cursor];}
    char get(pos ht, pos wd) const { return contents[ht * wd];}
    Screen set(char c);
    Screen move(pos row, pos col);
    void display(std::ostream &os) {os << contents;}
private:
    pos heigth = 0;
    pos width = 0;
    pos cursor = 0;
    std::string contents;
};

inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::move(pos row, pos col)
{
    cursor = row * width + col;
    return *this;
}

int main(void)
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}

