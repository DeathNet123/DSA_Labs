#include <iostream>
using namespace std;

int re_arrange(int *array, int low, int high);
void quick_sort(int *array, int low, int high);
void print_array(int *array, int size);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int data [7] = {8, 7, 6, 1, 0, 9, 2};
    print_array(data, 7);
    cout<<"\nData after being sorted\n";
    quick_sort(data, 0, 6);
    print_array(data, 7);
    return 0;
}

void print_array(int *array, int size)
{
    for(int idx = 0; idx < size; idx++)
    {
        cout<<array[idx]<<' ';
    }
    cout<<'\n';
}

int re_arrange(int *array, int low, int high)
{
    int pivot = array[high];
    int idx = low - 1;
    for(int kdx = low; kdx <= high; kdx++)
    {
        if(array[kdx] <= pivot)
        {
            idx++;
            swap(&array[kdx], &array[idx]);
        }
    }

    return idx;
}

void quick_sort(int *array, int low, int high)
{
    if(low < high)
    {
        int pivot = re_arrange(array, low, high);
        quick_sort(array, 0, pivot - 1);
        quick_sort(array, pivot + 1, high);
    } 
}