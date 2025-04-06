//
// Created by Erkam on 4/5/2025.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int    count = 5;
    string buffer, line;

    while (count-- > 0 && cin >> buffer)
    {
        line += buffer;
        line += " "; // Second part
    }
    cout << line << endl;

    return 0;
}
