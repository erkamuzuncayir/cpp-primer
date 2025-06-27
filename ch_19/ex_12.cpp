/***************************************************************************
 *  @file       ex_12.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>
#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;

    Screen(std::string s, pos h, pos w, pos c) : contents(std::move(s)), height(h), width(w), cursor(c) {}

    char get_cursor() const { return contents[cursor]; }

private:
    std::string contents;
    pos         cursor;
    pos         height, width;

    // Grant access to private members for test
    friend int main();
};

int main()
{
    Screen screen("Hello, world!", 1, 13, 7);

    Screen::pos Screen::*pCursor = &Screen::cursor;

    // Access through object
    Screen::pos val1 = screen.*pCursor;
    std::cout << "cursor position via object: " << val1 << "\n";
    std::cout << "character at cursor: " << screen.get_cursor() << "\n";

    // Access through pointer to object
    Screen     *ptr  = &screen;
    Screen::pos val2 = ptr->*pCursor;
    std::cout << "cursor position via pointer: " << val2 << "\n";
}
