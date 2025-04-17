//
// Created by erkam on 4/16/25.
//

#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::string;

void print(const char* cp)
{
    if (cp)
        while (*cp)
            cout << *cp++;
}

void print(const int* beg, const int* end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

int main(void)
{
    int         i      = 0;
    int         arr[4] = {0, 1, 2, 3};
    const char* ch     = "hello";

    print(ch);
    print(begin(arr), end(arr));
    print(arr, end(arr) - begin(arr));
}
