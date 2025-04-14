//
// Created by erkam on 4/14/25.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    int    word_count = 10, is_repeated = 0;
    string last,            curr;

    while (--word_count > 0)
    {
        cin >> curr;

        if (isupper(curr[0]) && last == curr)
        {
            cout << "Occur twice: " << last << "\n";
            is_repeated = 1;
            break;
        }
        last = curr;
    }

    while((sz = get_size()) <= 0)
        ;


    if (!is_repeated)
        cout << "No word is repeated!\n";
}
