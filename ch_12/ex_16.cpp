// -----------------------------------------------------------------------------
// File:        ex_16.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#include <memory>
int main()
{
    std::unique_ptr<int> first_unique(new int(42));
    std::unique_ptr<int> second_unique;
    // second_unique = first_unique;
    /*
    * error C2280: 'std::unique_ptr<int,std::default_delete<int>>
    &std::unique_ptr<int,std::default_delete<int>>::operator =(const std::unique_ptr<int,std::default_delete<int>> &)':
    attempting to reference a deleted function MSVC\14.44.35207\include\memory(3476): note: see declaration of
    'std::unique_ptr<int,std::default_delete<int>>::operator =' MSVC\14.44.35207\include\memory(3476): note:
    'std::unique_ptr<int,std::default_delete<int>> &std::unique_ptr<int,std::default_delete<int>>::operator =(const
    std::unique_ptr<int,std::default_delete<int>> &)': function was explicitly deleted
    */

    int                     ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;
    IntP                    p0(ix);
    IntP                    p1(pi);
    IntP                    p2(pi2);
    IntP                    p3(&ix);

    IntP p4(new int(2048));
    IntP p5(p2.get());
}
