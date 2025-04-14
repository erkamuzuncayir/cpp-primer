//
// Created by erkam on 4/14/25.
//

#include <iostream>

int main()
{
    int      ch_count    = 20;
    unsigned vowel_count = 0;
    char     ch;

    while (std::cin >> ch && ch_count-- > 0)
    {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch
            == 'u' || ch == 'U')
            vowel_count++;
    }

    std::cout << vowel_count << std::endl;
}
