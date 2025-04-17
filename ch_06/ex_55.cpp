//
// Created by erkam on 4/17/25.
//

#include <vector>
using std::vector;

int sum(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }
int mult(int n1, int n2) { return n1 * n2; }
int div(int n1, int n2) { return n2 != 0 ? n1 / n2 : 0; }


int main(void)
{
    vector<int (*)(int, int)> vec_ops;
    vec_ops.push_back(sum);
    vec_ops.push_back(sub);
    vec_ops.push_back(mult);
    vec_ops.push_back(div);
}
