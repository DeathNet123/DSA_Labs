#include <iostream>
using namespace std;

void swap(int *a, int *b);
void selection_sort(int *array, int size);

void print_array(int *array, int size)
{
    for(int idx = 0; idx < size; idx++)
    {
        cout<<array[idx]<<' ';
    }
    cout<<'\n';
}

int main(void)
{
    cout<<"Unsorted Data\n";
    int data [7]  ={8, 7, 6, 1, 0, 9, 2};
    print_array(data, 7);
    selection_sort(data, 7);
    cout<<"\nSorted Data\n";
    print_array(data, 7);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *array, int size)
{
    int min_idx {0};
    for(int idx = 0; idx < size; idx++)
    {
        min_idx = idx;
        for(int kdx = idx; kdx < size; kdx++)
        {
            if(array[kdx] < array[min_idx])
            {
                min_idx = kdx;
            }
        }
        swap(&array[min_idx], &array[idx]);
    }
}