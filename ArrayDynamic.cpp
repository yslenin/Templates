#include <iostream>
#include "ArrayDynamic.h"
using namespace std;
int main()
{
    ArrayDynamic<float> a;
    a.pushBack(5.5);
    a.pushBack(7.6);
    a.pushBack(7.5);
    a.print();
    a.insert(1.6, 0);
    a.insert(2.9, 3);
    a.print();
    a.remove(3);
    a.remove(0);
    a.print();
}
