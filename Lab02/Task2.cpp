#include<iostream>
#include<cmath>
using namespace std;
/*
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
bool check_prime(int number)
{
    int test = 0;
    if(number == 0 || number == 1)
        return false;
    for(int idx = 1; idx <= number; idx++)
    {
        if(number % idx == 0)
            test++;
    }
    if(test > 2)
        return false;
    else
        return true;
}
int print_numbers(int calc, int place, int number, int to_give)
{
    //Base Case
    int hold, temp;
    if (place >= to_give)
    {
        int remainning = number - calc;
        calc += remainning;
        if(remainning != 0)
            cout<<remainning;
        if(check_prime(remainning) && place <= remainning)
        {
            cout<<' '<<1;
        }
            
    } 
    if(calc == number)
        return 25; 
    for(int idx = 1; idx < to_give; idx++)
    {
        hold = pow(place, idx);
        if(hold > to_give)
        {
            if(hold == to_give)
                idx++;
            cout<<place<<' '<<idx-1<<' ';
            calc += pow(place, idx-1);
            break;
        }
    }
    to_give = number - calc;
    place = return_prime(place, number);
    print_numbers(calc, place, number, to_give);
    return 0;
}
int main(void)
{
    int n1;
    cin>>n1;
    cout<<print_numbers(0, 2, n1, n1);
    return 0;
}*/

