//
// Created by Erkam on 4/4/2025.
//

#include <iostream>

int main()
{
    int  obj_one = 1,         obj_two = 2;
    int *ptr_one = &obj_one, *ptr_two = &obj_two;

    std::cout << "Before operation obj_one: " << obj_one << std::endl;
    (*ptr_one)++;
    std::cout << "After operation obj_one: " << obj_one << std::endl;

    std::cout << "Before operation obj_two: " << obj_two << std::endl;
    (*ptr_two)--;
    std::cout << "After operation obj_two: " << obj_two << std::endl;
}
