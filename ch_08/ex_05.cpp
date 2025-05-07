//
// Created by erkam on 07/05/25.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void read(const string &file_name, vector<string> &vec_str)
{
    ifstream in(file_name);

    if (in)
    {
        string temp;
        while (in >> temp)
            vec_str.push_back(temp);
    }
}

int main(int argc, char *argv[])
{
    vector<string> vec_str;
    read(argv[1], vec_str);

    for (auto &str : vec_str)
        cout << str << endl;
}
