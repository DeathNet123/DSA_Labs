#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <numeric>
using namespace std;

int fine_division(int index, int size, vector<int> difference, vector<int> array)
{
    int temper;
    //base case..
    if(index == size)
    {
        int min_index = min_element(difference.begin(), difference.end()) - difference.begin();
        cout<<min_index + 1;
        return min_index;
    }
    int sum = accumulate(array.begin() + index + 1, array.end(), 0);
    int sum2 = accumulate(array.begin(), array.begin() + index + 1, 0);
    int minus = abs(sum2 - sum);
    difference.push_back(minus);
    fine_division(++index, size, difference, array);
    return 0;
}

int main(void) 
{
    int size, temp;
    vector <int> array;
    vector<int> difference;
    cin>>size;
    for(int idx = 0; idx < size; idx++)
    {
        cin>>temp;
        array.push_back(temp);
    }
    fine_division(0, size, difference, array);
    return 0;
}
