#include "complex.h"
#include <iostream>
using namespace std;
ostream &
operator<<(ostream &os, const complex &x)
{
    cout << '(' << real(x) << ',' << imag(x) << ')' << endl;
}
int main()
{
    complex c1(1, 3);
    complex c2(2, 4);
    complex c3;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c1 + c2 << endl;
    cout << c1 + 3<<endl;
    cout << 3 + c2<<endl;
    return 0;
}