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
    string temp, line;

    while (count-- > 0 && cin >> temp)
    {
        int size = temp.length();
        for (int i = 0; i < size; i++)
        {
            if (!ispunct(temp[i]))
                line += temp[i];
        }
        line += " "; // Second part
    }
    cout << line << endl;

    return 0;
}
