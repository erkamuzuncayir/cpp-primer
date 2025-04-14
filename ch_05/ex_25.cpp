//
// Created by erkam on 4/14/25.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    double first_num, second_num;

    try
    {
        cout << "Enter two number: ";
        cin >> first_num >> second_num;
        if (second_num == 0)
            throw runtime_error("Division by zero. ");
    }
    catch (runtime_error& err)
    {
        cout << err.what() << "Enter a new number: ";
        cin >> second_num;
        if (second_num == 0)
            return -1;
    }

    cout << first_num / second_num << endl;
}
