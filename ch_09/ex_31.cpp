//
// Created by erkam on 09/05/25.
//

#include <forward_list>
#include <iostream>
#include <list>

using std::cout;
using std::forward_list;
using std::list;

void ModifyList(std::list<int> &lst)
{
    auto curr = lst.begin();

    while (curr != lst.end())
    {
        if (*curr % 2)
        {
            curr = lst.insert(curr, *curr);
            ++curr;
            ++curr;
        }
        else
            curr = lst.erase(curr);
    }
}

void ModifyForwardList(std::forward_list<int> &flst)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            prev = flst.insert_after(prev, *curr); 
            ++prev;                                
            ++curr;
        }
        else
            curr = flst.erase_after(prev);
    }
}


int main(void)
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int>         lst  = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    ModifyList(lst);
    ModifyForwardList(flst);

    cout << "List: ";
    for (int e : flst)
        cout << e << ' ';

    cout << "\nForward List: ";
    for (int e : flst)
        cout << e << ' ';
}
