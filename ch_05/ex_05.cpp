//
// Created by erkam on 4/14/25.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int                  grade  = 91;
    string               letter_grade;

    if (grade < 60)
        letter_grade = scores[0];
    else
    {
        letter_grade = scores[(grade - 50) / 10];
        if (grade != 100)
            letter_grade += (grade % 10 > 7) ? "+" : (grade % 10 < 3 ? "-" : "");
    }
    cout << letter_grade << endl;
}
