//
// Created by erkam on 4/8/25.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    int grade = 91;

    auto result = grade > 90 ? "high pass" : grade < 60 ? "fail" : grade < 75 ? "low pass" : "pass";
    cout << result << endl;

    cout << (~'q'<<6)<<endl;
    if (grade > 90)
        cout << "high pass";
    else if (grade < 60)
        cout << "fail";
    else if (grade < 75)
        cout << "low pass";
    else
        cout << "pass";
    cout << endl;
}
