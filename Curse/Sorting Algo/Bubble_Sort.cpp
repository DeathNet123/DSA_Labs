#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int size)
{
    
    for(int idx = 0; idx < size; idx++)
    {
        bool swapped = false;
        for(int kdx = 0; kdx < size - 1; kdx++)
        {
            if(array[kdx] > array[kdx + 1])
            {
                swapped = true;
                swap(&array[kdx], &array[kdx + 1]);
            }
        }
        if(swapped == false)
            return;    
    }
}

void print_array(int *array, int size)
{
    for(int idx = 0; idx < size; idx++)
    {
        cout<<array[idx]<<" ";
    }
    cout<<'\n';
}
int main(void)
{
    int array[7] = {8, 7, 6, 1, 0, 9, 2};
    cout<<"\nUnsorted Data\n";
    print_array(array, 7);
    cout<<"\nSorted Data\n";
    bubble_sort(array, 7);
    print_array(array, 7);
    return 0;
}