#include<iostream>
using namespace std;

void index_check(int *array, int *index, const int size)
{
    int temp {0};
    for(int idx = 0; idx < size; idx++)
    {
        for(int kdx = 0; kdx < size - 1; kdx++)
        {
            if(array[index[kdx]] > array[index[kdx + 1]])
            {
                temp = index[kdx];
                index[kdx] = index[kdx + 1];
                index[kdx + 1] = temp;
            }
        }
    }
}


int main(void)
{
    int array_0[10] = {10, 9, 7, 8, 5, 6, 3, 4, 1, 2};
    int array_1[10] = {35, 26, 29, 88, 85, 86, 89, 10, 90, 84};
    int array_2[10] = {60, 26, 50, 88, 89, 10, 89, 10, 75, 86};
    int index[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<"Before Sorting for the refrence..\n";
    for(int idx = 0; idx < 10; idx++)
        cout<<array_0[idx]<<' '<<array_1[idx]<<' '<<array_2[idx]<<'\n';  
    index_check(array_0, index, 10);
    cout<<"After Sorting for the refrence..\n";
    for(int idx = 0; idx < 10; idx++)
        cout<<array_0[index[idx]]<<' '<<array_1[index[idx]]<<' '<<array_2[index[idx]]<<'\n';
    return 0;
}