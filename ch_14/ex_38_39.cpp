// -----------------------------------------------------------------------------
// File:        ex_38_39.cpp
// Author:      Erkam Uzuncayir
// Date:        19/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
class Is_In_Bound
{
public:
    Is_In_Bound(size_t l_b, size_t u_b) : lower_bound(l_b), upper_bound(u_b) {};
    bool operator()(const std::string &str) const
    {
        const size_t len = str.length();
        return len >= lower_bound && len <= upper_bound;
    }

private:
    size_t lower_bound;
    size_t upper_bound;
};

void ex_38(std::ifstream in_file)
{
    std::string word;
    unsigned    between_one_and_ten_word_count = 0;
    Is_In_Bound bound_checker(1, 10);

    while (in_file >> word)
    {
        if (bound_checker(word))
            ++between_one_and_ten_word_count;
    }

    std::cout << between_one_and_ten_word_count << " amount of words' length in between 1 and 10.\n";
}

void ex_39(std::ifstream in_file)
{
    std::string word;
    unsigned    between_one_and_nine_word_count = 0;
    unsigned    more_than_nine_word_count       = 0;

    Is_In_Bound bound_checker(1, 9);

    while (in_file >> word)
    {
        if (bound_checker(word))
            ++between_one_and_nine_word_count;
        else
            ++more_than_nine_word_count;
    }

    std::cout << between_one_and_nine_word_count << " amount of words' length in between 1 and 9.\n"
              << more_than_nine_word_count << " amount of words' length more than nine.\n";
}
int main()
{
    std::ifstream in_file("***/input.txt");
    if (!in_file)
        return 1;

    // ex_38
    ex_38(std::move(in_file));

    // ex_39
    ex_39(std::move(in_file));
}
