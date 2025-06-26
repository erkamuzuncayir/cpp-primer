// -----------------------------------------------------------------------------
// File:        ex_34_35_36.cpp
// Author:      Erkam Uzuncayir
// Date:        26/06/2025
// -----------------------------------------------------------------------------

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    bool   b  = true;
    int    n  = 42;
    double pi = 3.1415926535;

    cout << "=== boolalpha / noboolalpha ===\n";
    cout << boolalpha << b << " " << !b << endl;
    cout << noboolalpha << b << " " << !b << endl;

    cout << "\n=== showbase / noshowbase ===\n";
    cout << showbase;
    cout << "Decimal: " << dec << n << "\n";
    cout << "Hex: " << hex << n << "\n";
    cout << "Oct: " << oct << n << "\n";
    cout << noshowbase;

    cout << "\n=== showpoint / noshowpoint ===\n";
    cout << showpoint << 10.0 << "\n";
    cout << noshowpoint << 10.0 << "\n";

    cout << "\n=== showpos / noshowpos ===\n";
    cout << showpos << 10 << " " << -10 << "\n";
    cout << noshowpos << 10 << " " << -10 << "\n";

    cout << "\n=== uppercase / nouppercase (hex + scientific) ===\n";
    cout << uppercase << hex << showbase << n << "\n";
    cout << scientific << pi << "\n";
    cout << nouppercase << hex << showbase << n << "\n";
    cout << scientific << pi << "\n";

    cout << "\n=== dec / hex / oct ===\n";
    cout << dec << n << " " << hex << n << " " << oct << n << "\n";

    cout << "\n=== left / right / internal with setw(10) and setfill('*') ===\n";
    cout << setfill('*');
    cout << left << setw(10) << 123 << "\n";
    cout << right << setw(10) << 123 << "\n";
    cout << internal << setw(10) << -123 << "\n";

    cout << "\n=== fixed / scientific / hexfloat / defaultfloat ===\n";
    cout << fixed << pi << "\n";
    cout << scientific << pi << "\n";
    cout << hexfloat << pi << "\n";
    cout << defaultfloat << pi << "\n";

    cout << "\n=== unitbuf / nounitbuf ===\n";
    cout << unitbuf << "Flushed immediately\n";
    cout << nounitbuf;

    cout << "\n=== skipws / noskipws with input ===\n";
    istringstream in1("   100");
    int           x;
    in1 >> skipws >> x;
    cout << "With skipws: " << x << "\n";

    istringstream in2("   100");
    x = 0;
    in2 >> noskipws >> x; // won't read anything due to whitespace
    cout << "With noskipws: " << x << "\n";

    cout << "\n=== flush / ends / endl ===\n";
    cout << "Hello" << flush;       // flushes buffer, no newline
    cout << "\nHi" << ends << "\n"; // adds null character, flushes
    cout << "World" << endl;        // newline and flush

    cout << "\n=== setfill, setprecision, setw, setbase ===\n";
    cout << setfill('#') << setw(10) << 77 << "\n";
    cout << setprecision(4) << pi << "\n";
    cout << setbase(16) << 255 << "\n";

    // ex_35
    cout << "hexadecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << '\n';

    // ex_36
    cout << "=== Aligned Floating-Point Formats ===\n";

    cout << left << setw(15) << "Format" << setw(25) << "Value" << "\n";
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << "\n";

    cout << left << setw(15) << "fixed"
         << right << setw(25) << fixed << setprecision(6) << pi << "\n";

    cout << left << setw(15) << "scientific"
         << right << setw(25) << scientific << setprecision(6) << pi << "\n";

    cout << left << setw(15) << "hexfloat"
         << right << setw(25) << hexfloat << pi << "\n";

    cout << left << setw(15) << "defaultfloat"
         << right << setw(25) << defaultfloat << pi << "\n";

    return 0;
}
