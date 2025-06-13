// -----------------------------------------------------------------------------
// File:        ex_20.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>

#include "ex_19.h"

int main()
{
    std::ifstream in("***/input.txt");
    StrBlob       blob;
    if (in)
    {
        string temp;
        while (std::getline(in, temp))
            blob.push_back(temp);

        for (StrBlobPtr ptr_beg(blob.begin()), ptr_end(blob.end()); ptr_beg.current_position() != ptr_end.current_position(); ptr_beg.incr())
            std::cout << ptr_beg.deref() << std::endl;
    }
}
