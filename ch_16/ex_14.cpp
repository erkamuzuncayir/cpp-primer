// -----------------------------------------------------------------------------
// File:        ex_14.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------


#include <iostream>
#include <string>

template <std::size_t Height, std::size_t Width>
class Screen
{
    friend std::istream &operator>>(std::istream &is, Screen<size_t, size_t> &s);
    friend std::ostream &operator<<(std::ostream &os, Screen<size_t, size_t> &s);

public:
    using pos = std::size_t;

    Screen() : contents(Height * Width, ' ') {}

    char get() const { return contents[cursor]; }

    char get(pos r, pos c) const { return contents[r * Width + c]; }

    Screen &move(pos r, pos c)
    {
        cursor = r * Width + c;
        return *this;
    }

    Screen &set(char ch)
    {
        contents[cursor] = ch;
        return *this;
    }

    Screen &set(pos r, pos c, char ch)
    {
        contents[r * Width + c] = ch;
        return *this;
    }

    void display(std::ostream &os) const
    {
        for (pos r = 0; r < Height; ++r)
        {
            for (pos c = 0; c < Width; ++c)
            {
                os << contents[r * Width + c];
            }
            os << '\n';
        }
    }

private:
    std::string contents;
    pos         cursor = 0;
};


std::istream &operator>>(std::istream &is, Screen<size_t, size_t> &s)
{
    for (std::size_t i = 0; i < (s.Height * s.Width); ++i)
        is >> s.contents[i];

    return is;
}

std::ostream &operator<<(std::ostream &os, Screen<size_t, size_t> &s)
{
    for (std::size_t r = 0; r < s.Height; ++r)
    {
        for (std::size_t c = 0; c < s.Width; ++c)
            std::cout << s.contents[r * s.Width + c];

        std::cout << '\n';
    }
    return os;
}
