#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int            count = 10;
    string         temp;
    vector<string> words;

    while (count-- > 0 && cin >> temp)
        words.push_back(temp);

    for (int i = 0; i < words.size(); i++)
    {
        for (int j      = 0; j < words[i].size(); j++)
            words[i][j] = toupper(words[i][j]);
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (i != 0 && i % 8 == 0)
            cout << endl << words[i] << " ";
        else
            cout << words[i] << " ";
    }

    return 0;
}
