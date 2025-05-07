//
// Created by erkam on 07/05/25.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

void read_line(const string &file_name, vector<string> &vec_line)
{
    ifstream in(file_name);

    if (in)
    {
        string temp;
        while (getline(in, temp))
            vec_line.push_back(temp);
    }
}

void read_word(const vector<string> &vec_line, vector<string> &vec_word)
{
    string word;

    for (auto l : vec_line)
    {
        istringstream sin(l);
        while (sin >> word)
        {
            vec_word.push_back(word);
        }
    }
}

int main(int argc, char *argv[])
{
    vector<string> vec_line;
    read_line(argv[1], vec_line);

    cout << "Lines: \n";
    for (auto &line : vec_line)
        cout << line << endl;

    vector<string> vec_word;
    read_word(vec_line, vec_word);

    cout << "Words: \n";
    for (auto &word : vec_word)
        cout << word << endl;
}
