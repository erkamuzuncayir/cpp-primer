//
// Created by erkam on 4/16/25.
//

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;

    return ret;
}