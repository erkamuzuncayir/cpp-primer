// -----------------------------------------------------------------------------
// File:        ex_14_15.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <regex>

void ex_14()
{
    try
    {
        // Missing closing bracket
        std::regex r1("[a-z");
    }
    catch (std::regex_error &e)
    {
        std::cerr << "Regex error in r1: " << e.what() << '\n';
    }

    try
    {
        // Invalid repetition quantifier
        std::regex r2("a{2,1}");
    }
    catch (std::regex_error &e)
    {
        std::cerr << "Regex error in r2: " << e.what() << '\n';
    }

    try
    {
        // Invalid escape sequence
        std::regex r3("\\xZ");
    }
    catch (std::regex_error &e)
    {
        std::cerr << "Regex error in r3: " << e.what() << '\n';
    }

    try
    {
        // Invalid character class range
        std::regex r4("[z-a]");
    }
    catch (std::regex_error &e)
    {
        std::cerr << "Regex error in r4: " << e.what() << '\n';
    }
}

void ex_15()
{
    std::string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::regex reg_pattern(pattern);
    std::string word;

    std::cout << "Enter words (type 'exit' to quit):\n";
    while (std::cin >> word && word != "exit") {
        if (std::regex_search(word, reg_pattern)) {
            std::cout << word << " violates the rule!\n";
        } else {
            std::cout << word << " follows the rule.\n";
        }
    }
}

int main()
{
    // ex_14();
    ex_15();
}
