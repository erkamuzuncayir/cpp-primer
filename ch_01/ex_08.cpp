//
// Created by Erkam on 4/2/2025.
//

#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */; -> illegal one.
    std::cout << /* "*/" /* "/*" */;

    return 0;
}
