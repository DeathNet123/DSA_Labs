#include<iostream>
#include<cmath>
using namespace std;

int return_prime(int start, int number)
{
    int test {0};
    for(int idx = start + 1; idx < number; idx++)
    {
        for(int kdx = 1; kdx <= idx; kdx++)
        {
            if(idx % kdx == 0)
                test++;
        }
        if(test == 2)
            return idx;
        test = 0;
    }
    return 0;
}
int print_numbers(int calc, int place, int number)
{
    //Base Case
    int hold, hold2 = 0, temp;
    if(calc >= number)
    {
        return 0;
    }
    for(int idx = 1; true; idx++)
    {
        calc += idx;
    }
    cin>>temp;
    cout<<"\ncalc:"<<calc;
    place = return_prime(place, number);
    cout<<"next: "<<place<<endl;
    print_numbers(calc, place, number);
    return 0;
    
}
int main(void)
{
    int n1;
    cin>>n1;

    print_numbers(0, 2, n1);
    return 0;
}