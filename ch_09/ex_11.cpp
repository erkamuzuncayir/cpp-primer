//
// Created by erkam on 08/05/25.
//

#include <vector>
using std::vector;

int main(void)
{
    vector<int> iv_1;                           // Nothing
    vector<int> iv_2(10);                       // Nothing
    vector<int> iv_3{1, 2, 3};                  // 1, 2, 3
    vector<int> iv_4 = {4, 5, 6};               // 4, 5, 6
    vector<int> iv_5(iv_4);                     // 4, 5, 6
    vector<int> iv_6 = iv_3;                    // 1, 2, 3
    vector<int> iv_7(iv_3.begin(), iv_3.end()); // 1, 2, 3
}
