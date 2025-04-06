//
// Created by Erkam on 4/5/2025.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n_1, n_2;

    cout << "Please enter two integer: ";
    cin >> n_1;
    cin >> n_2;

    n_1++;
    while (n_1 < n_2)
        cout << n_1++ << " ";

    cout << endl;

    return 0;
}
