#include<iostream>
using namespace std;

#define DATA_ERROR -99
#define ILLEGAL_OPERATION -6

int loop;
class Integer_calc
{
    private:
        char sign;
        int temp, temp1;
    public:
        Integer_calc(int temp = 0, int temp1 = 1, char sign = 0)
        {

        }
        void functions(void)
        {
        try
        {
            cin>>temp>>temp1;
            if(cin.fail())
            {
                cin.clear();
                throw DATA_ERROR;
            }
            cin>>sign;
            if(sign != '+' && sign != '-' && sign != '*' && sign != '/')
            {
                cin.ignore();
                throw ILLEGAL_OPERATION;
            }
                  switch(sign)
        {
            case '+':
                cout<<temp1+temp<<'\n';
                break;
            case '-':
                cout<<temp-temp1<<'\n';
                break;
            case '*':
                cout<<temp1*temp<<'\n';
                break;
            case '/':
                if (temp1 == 0)
                    throw DATA_ERROR;
                cout<<temp/temp1<<'\n';
                break;
        }
        }
        catch(int test)
        {
            if(test == DATA_ERROR)
            {
                cout<<"DATA_ERROR\n";
            }
            else if(test == ILLEGAL_OPERATION)
            {
                cout<<"ILLEGAL_OPERATION\n";
            }
        }
  

        }
};
int main(void)
{
    Integer_calc in;
    cin>>loop;
    for(int idx = 0; idx < loop; idx++)
    {
        in.functions();
    }
    return 0;
}