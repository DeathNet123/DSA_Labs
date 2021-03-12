#include <iostream>
using namespace std;

int main(void)
{
    int *array, *array_1, *array_2;
    int size;

    cin>>size;
    array = new int[size];
    array_1 = new int[size];
    array_2 = new int[size];

    for(int idx = 0; idx < size; idx++)
    {
        cin>>array[idx]>>array_1[idx]>>array_2[idx];
    }

/****************************************************************************************************************************************************/


    return 0;
}