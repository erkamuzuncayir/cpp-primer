// -----------------------------------------------------------------------------
// File:        ex_37.cpp
// Author:      Erkam Uzuncayir
// Date:        26/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream infile("***/input.txt");

    if (!infile)
    {
        cerr << "Could not open the file.\n";
        return 1;
    }

    const int SIZE = 50;
    char      buffer[SIZE];

    int line_num = 1;
    while (infile)
    {
        infile.getline(buffer, SIZE);

        cout << "Line " << line_num << " (part): [" << buffer << "]" << endl;

        if (infile.gcount() < SIZE - 1 || infile.eof())
            ++line_num;

        if (infile.fail() && !infile.eof())
            infile.clear();
    }

    return 0;
}
