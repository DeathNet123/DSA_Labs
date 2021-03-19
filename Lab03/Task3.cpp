#include <iostream>
using namespace std;

bool check_hack(int number, int value)
{
    if(value == number)
        return true;
    else if(value > number)
        return false;
    return check_hack(number, value * 10) || (number, value * 20); 

}
int main(void)
{
    int cases;
    int number;
    cin>>cases;
    while(cases--)
    {
        cin>>number;
        if(check_hack(number, 1))
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }
    
    return 0;
}