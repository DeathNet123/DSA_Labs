#include<iostream>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
/*void bubbleSort(int *array, int size, int *array_1, int *array_2) 
{
    int temp;
  for (int step = 0; step < size - 1; ++step) 
  {
    int swapped = 0;
    for (int i = 0; i < size - step - 1; ++i) 
    {
      if (array[i] > array[i + 1]) 
      {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        temp = array_1[i];
        array_1[i] = array_1[i + 1];
        array_1[i + 1] = temp;
        temp = array_2[i];
        array_2[i] = array_2[i + 1];
        array_2[i + 1] = temp;
      }

      }
    }
}*/

int main(void)
{
    int size, k, list, index;
    int *array, *array_1, *array_2;
    cin>>size;

    array = new int[size];
    array_1 = new int[size];
    array_2 = new int[size];
    for(int idx = 0; idx < size; idx++)
    {
        cin>>array[idx]>>array_1[idx]>>array_2[idx];       
    }
    cin>>k;
    for(int idx = 0; idx < k; idx++)
    {
        cin>>list>>index;
         switch(list) 
         {
            case 0:
                for (int step = 0; step < size - 1; ++step) 
                {
                    for (int i = 0; i < size - step - 1; ++i) 
                    {
                        if (array[i] > array[i + 1]) 
                        {
                            swap(&array[i], &array[i + 1]);
                            swap(&array_1[i], &array_1[i + 1]);
                            swap(&array_2[i], &array_2[i + 1]);
                        }
                    }
                }
                break;
                case 1:
                for (int step = 0; step < size - 1; ++step) 
                {
                    for (int i = 0; i < size - step - 1; ++i) 
                    {
                        if (array_1[i] > array_1[i + 1]) {
                            swap(&array[i], &array[i + 1]);
                            swap(&array_1[i], &array_1[i + 1]);
                            swap(&array_2[i], &array_2[i + 1]);
                        }
                    }
                }
                break;
                case 2:
                for (int step = 0; step < size - 1; ++step) 
                {
                    for (int i = 0; i < size - step - 1; ++i) 
                    {
                        if (array_2[i] > array_2[i + 1]) 
                        {
                            swap(&array[i], &array[i + 1]);
                            swap(&array_1[i], &array_1[i + 1]);
                            swap(&array_2[i], &array_2[i + 1]);
                        }
                    }
                }
                break;
        }
        
    }
    return 0;
}

