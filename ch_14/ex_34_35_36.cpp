// -----------------------------------------------------------------------------
// File:        ex_34_35_36.cpp
// Author:      Erkam Uzuncayir
// Date:        18/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

class GetString
{
public:
    GetString(std::istream &i = std::cin) : is(i) {}

    int operator()(bool condition, int param_1, int param_2) const { return condition ? param_1 : param_2; }

    std::string operator()(std::string &str)
    {
        if (getline(is, str))
            return str;

        return std::string();
    }

    void operator()()
    {
        std::string tmp;
        while (is)
        {
            if (getline(is, tmp))
                lines.push_back(tmp);
        }
    }
    void print_lines() const
    {
        for (const auto &line : lines)
            std::cout << line << std::endl;
    }

private:
    std::istream            &is;
    std::vector<std::string> lines;
};

int main()
{
    GetString gs; // std::cin is passed by default

    // 1. Test: operator()(bool, int, int)
    std::cout << "Condition test: " << gs(true, 10, 20) << std::endl;  // Expected output: 10
    std::cout << "Condition test: " << gs(false, 10, 20) << std::endl; // Expected output: 20

    // 2. Test: operator()(std::string&)
    std::cout << "Please enter a line of text (string input test): ";
    std::string input;
    std::string result = gs(input);
    std::cout << "You entered: " << result << std::endl;

    // 3. Test: operator()() — multiple line input
    std::cout << "Enter multiple lines (empty line to stop):\n";
    GetString multi_input;
    multi_input(); // Reads all lines using getline, stores in 'lines' — but 'lines' is private

    multi_input.print_lines();

    return 0;
}
