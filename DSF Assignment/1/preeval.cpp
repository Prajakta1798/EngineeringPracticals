
/*
********************************************************************************************************************
                                   ASSIGNMENT NO:
ROLL NO:                                                                                   BATCH :
__________________________________________________________________________________________________________________
TITTEL:     Evalution of prefix expression.
**************************************************************************************************************/
#include<iostream>
#include"stack.h"
using namespace std;
stack ob;
class postfix
{
public:
    char*s;
    void set_exp(char *str)
    {
        do
            s=str++;
        while(*str!='\0');
    }
    void calculate()
    {
        int n1,n2,n3,n;
        while(*s)
        {
            if(*s==' '||*s=='\t')
            {
                s--;
                continue;
            }
            if(isdigit(*s))
            {
                n=*s-'0';
                ob.push(n);
                s--;
            }
            else
            {
                n1=ob.pop();
                n2=ob.pop();
                switch(*s)
                {
                case '+' :
                    n3=n2+n1;
                    break;
                case '-' :
                    n3=n2-n1;
                    break;
                case '*' :
                    n3=n2*n1;
                    break;
                case '/' :
                    n3=n2/n1;
                    break;
                case '%' :
                    n3=n2%n1;
                    break;
                }
                ob.push(n3);
                s--;
            }
        }
    }
    void show()
    {
        int no;
        no=ob.pop();
        cout<<no<<"\n";
    }
};
int main()
{
    char str[50];
    postfix OB;
    cout<<"Enter the prefix expression : ";
    cin>>str;
    OB.set_exp(str);
    OB.calculate();
    cout<<"\nResult is ";
    OB.show();
    return 0;
}
/*

OUTPUT:
it@IT-PL-5:~$ cd Desktop
it@IT-PL-5:~/Desktop$ g++ preeva.cpp
it@IT-PL-5:~/Desktop$ ./a.out
Enter the prefix expression : +3+4/20 4

Result is 12
it@IT-PL-5:~/Desktop$ 




*/
