//
// Created by erkam on 4/14/25.
//

#include <iostream>

int main()
{
    int      ch_count = 20;
    unsigned aCnt     = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char     ch;

    while (std::cin >> ch && ch_count-- > 0)
    {
        switch (ch)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
        }
    }

    std::cout << "A count: " << aCnt << std::endl;
    std::cout << "E count: " << eCnt << std::endl;
    std::cout << "I count: " << iCnt << std::endl;
    std::cout << "O count: " << oCnt << std::endl;
    std::cout << "U count: " << uCnt << std::endl;
}
