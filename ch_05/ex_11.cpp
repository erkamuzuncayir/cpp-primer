//
// Created by erkam on 4/14/25.
//

#include <iostream>

int main()
{
    int      ch_count = 20;
    unsigned a_cnt    = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0, blank_count = 0;
    int      ch;

    while ((ch = std::getchar()) != '\0' && ch_count-- > 0)
    {
        switch (ch)
        {
            case 'a':
            case 'A':
                ++a_cnt;
                break;
            case 'e':
            case 'E':
                ++e_cnt;
                break;
            case 'i':
            case 'I':
                ++i_cnt;
                break;
            case 'o':
            case 'O':
                ++o_cnt;
                break;
            case 'u':
            case 'U':
                ++u_cnt;
                break;
            case ' ':
            case '\t':
            case '\n':
                ++blank_count;
                break;
        }
    }

    std::cout << "A count: " << a_cnt << std::endl;
    std::cout << "E count: " << e_cnt << std::endl;
    std::cout << "I count: " << i_cnt << std::endl;
    std::cout << "O count: " << o_cnt << std::endl;
    std::cout << "U count: " << u_cnt << std::endl;
    std::cout << "Blank count: " << blank_count << std::endl;
}
