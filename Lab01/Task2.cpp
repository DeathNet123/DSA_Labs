#include<iostream>

using namespace std;

int main(void)
{
    int **array;
    int k {0};
    int size {0};
    cin>>size;
    if(size % 2 == 0 && size < 3)
    {
        return 0;
    }
    array = new int *[size];
    for(int idx = 0; idx < size; idx++)
    {
        array[idx] = new int[size]; 
    }
    for(int idx = 0; idx < size; idx++)
    {
        for(int kdx = 0; kdx < size; kdx++)
        {
            cin>>array[idx][kdx];
        }
    }
    cin>>k;
    if(k >= 1)
    {
        int center = size / 2;
        int x, y;
    for(int idx = 0; idx < k; idx++)
    {
        cin>>x>>y;
        if(center + x >= size || center + y >= size)
            cout<<"INVALID INPUT"<<'\n'; 
        else if(center + x < size || center + y < size)
        cout<<array[center - x][center + y]<<'\n';
    }
    }
    return 0;
}
