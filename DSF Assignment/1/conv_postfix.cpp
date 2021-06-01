
/*
********************************************************************************************************************
                                   ASSIGNMENT NO:
ROLL NO:                                                                                   BATCH :
__________________________________________________________________________________________________________________
TITTEL:     CONVERSION FROM INFIX TO POSTFIX.
**************************************************************************************************************/
#include<iostream>
#include<stack>
using namespace std;
class postfix
{
public:
     stack ob;
    char *s;
    void set_exp(char *str)
    {
        s=str;
    }

    void convert()
    {
        char opr;
        while(*s)
        {
            if(isdigit(*s)||isalpha(*s))
            {
                cout<<*s;
                s++;
            }
            else if(*s=='(')
            {
                ob.push(*s);
                s++;
            }
            else if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%'||*s=='^')
            {
                if(ob.top==NULL)
                {
                    ob.push(*s);
                    s++;
                }
                else
                {
                    opr=ob.pop();
                    while(priority(opr)>=priority(*s))
                    {
                        cout<<opr;
                        opr=ob.pop();
                    }
                    ob.push(opr);
                    ob.push(*s);
                    s++;
                }
            }
            else if(*s==')')
            {
                opr=ob.pop();
                while(opr!='(')
                {
                    cout<<opr;
                    opr=ob.pop();
                }
                s++;
            }
        }
        while(ob.top!=NULL)
        {
            opr=ob.pop();
            cout<<opr;
        }
    }

    int priority(char c)
    {
        if(c=='^')
            return 3;
        else if(c=='*'||c=='/'||c=='%')
            return 2;
        else if(c=='+'||c=='-')
            return 1;
        else
            return 0;
    }
};

int main()
{
    char str[50];
    postfix OB;
    cout<<"Enter the infix expression : ";
    cin>>str;
    OB.set_exp(str);
    cout<<"\nPostfix expression is : ";
    OB.convert();
    return 0;
}
/******************************************************************************
OUTPUT:
Enter the infix expression : p*q^r+s

Postfix expression is : pqr^*s+
******************************************************************************************/



