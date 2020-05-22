#include <iostream>
#include "dynamicarray.h"
using namespace std;

int main()
{
    DynamicArray<int> array1;
    array1[7] = 33;
    array1.print();
    DynamicArray<int> array2(array1);
    array2[2] = 22;
    array2.print();
    cout<<endl;
    array1.print();
    DynamicArray<int> array3(15);

    if(array3.isContains(0))
        cout<<endl<<"array3 is contain 0"<<endl;
    if(array2.isContains(2))
        cout<<endl<<"array2 is contain 2"<<endl;
    else
        cout<<endl<<"array2 is not contain 2"<<endl;


    array1.clear();
    if(array1.isEmpty())
        cout<<endl<<"array1 is Empty"<<endl;
    else
        cout<<endl<<"array1 is not Empty"<<endl;

    if(array1.resize(3))
        array1.print();

    cout<<endl<<"array2 size: "<<array2.size();
    return 0;
}
