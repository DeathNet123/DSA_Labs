#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

#define DEFAULT -1
class Collection
{
    public:
        int size; // size of the array default 1..
        int *data; // array which will hold the data..
        int current_size; // current size of the array index holder..

        void copier(const Collection &col)
        {
            this->size = col.size;
            this->data = new int[size];
            this->current_size = col.current_size;
            for(int idx = 0; idx < current_size; idx++)
            {
                this->data[idx] = col.data[idx];
            }
        }
    public:
        Collection(const int size = 1)
        {
            this->size = size;
            data = new int[size];
            current_size = 0;
            for(int idx = 0; idx < size; idx++)
            {
                data[idx] = -1;
            }
        }
        Collection(const int *array, int size)
        {
            this->size = size;
            this->current_size = size;
            data = new int[size];
            for(int idx = 0; idx < size; idx++)
            {
                this->data[idx] = array[idx];
            }
        }
        Collection(const Collection &col)
        {
           copier(col);
        }

        Collection operator = (const Collection &col)
        {
            delete [] data;
            copier(col);
            return *this;
        }
        int count_occurences(const int key) const
        {
            int count = 0;
            try
            {
                for(int idx = 0; idx < current_size; idx++)
                {
                    if(data[idx] == key)
                        count++;
                }
                if(count == 0)
                    throw -1;
                else
                    cout<<"Count: "<<count<<'\n'; 
            }
            catch(int type)
            {
                if(type == -1)
                    cout<<"Key not found..\n";
            }
            return count;
        }
        bool operator == (const Collection &col)
        {
            bool flag = true;
            int temp;
            int *arr;
            arr = new int [col.size];
            if(this->size != col.size || this->current_size != col.current_size)
            {
                flag = false;
                return flag;
            }
            for(int idx = 0; idx < current_size; idx++)
            {
                arr[idx] = col.data[idx];
            }
            sort(data, data + current_size);
            sort(arr, arr + current_size);
            for(int idx = 0; idx < current_size; idx++)
            {
                if(data[idx] != arr[idx])
                {
                    flag = false;
                    return false;
                }
            }
            delete [] arr;
            return flag;
        }
        void operator + (int k)
        {
                if(current_size != size)
                {
                    if(k >= 0 )
                        k = -1;
                    data[current_size++] = k;
                }
                else
                    cout<<"Array is Filled";
                      
           
        }
        Collection operator + (const Collection &col)
        {
            Collection result(this->size);
            if(current_size == col.current_size)
            {
                for(int idx = 0; idx < current_size; idx++)
                {
                    result.data[idx] = col.data[idx] + data[idx];
                }
            }
            else
            {
                cout<<"Failed array is not of the same size";
            }
            return result;
        }
        ~Collection()
        {
            delete[] data;
        }
        friend ostream& operator << (ostream& os, const Collection& col)
        {
            for(int idx = 0; idx < col.current_size; idx++)
            {
                cout<<col.data[idx]<<' ';
            }
            return os;
        }
};

int main(void)
{
    int loop, temp, fake;
    Collection *c;
    cin>>loop;
    
    for(int idx = 0; idx < loop; idx++)
    {
        cin>>temp;
        switch(temp)
        {
            case 1:
                cin>>fake;
                c = new Collection(fake);
                break;
            case 2:
                cin>>fake;
                *c + fake;
                break;
            case 3:
                cout << *c<<'\n';
                break;
            case 6:
                c->~Collection();
                break;
            case 7:
                cin>>fake;
                cout<<c->count_occurences(fake)<<'\n';
        }
    }
    
}
