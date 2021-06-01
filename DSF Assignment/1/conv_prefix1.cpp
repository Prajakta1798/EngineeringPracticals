
/**************************************************************
                                   ASSIGNMENT NO:
ROLL NO:                                                                                   BATCH :
TITTEL:     conversion of infix to  prefix expression.
***********************************************************/
#include<iostream>
#include"stack.h"
#include<string.h>
using namespace std;
stack ob;
class postfix
{
  public:
	char *s;
	void set_exp(char *str)
	{
		s = str;
	}

	void convert()
	{
		char opr, p[50], q[50];
		int i = 0;
		while (*s)
		{
			if (isdigit(*s) || isalpha(*s))
			{
				p[i++] = *s;
				s++;
			}
			else if (*s == ')')
			{
				ob.push(*s);
				s++;
			}
			else if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%' || *s == '^')
			{
				if (ob.top == NULL)
				{
					ob.push(*s);
					s++;
				}
				else
				{
					opr = ob.pop();
					while (priority(opr) >= priority(*s))
					{
						p[i++] = opr;
						opr = ob.pop();
					}
					ob.push(opr);
					ob.push(*s);
					s++;
				}
			}
			else if (*s == '(')
			{
				opr = ob.pop();
				while (opr != ')')
				{
					p[i++] = opr;
					opr = ob.pop();
				}
				s++;
			}
		}
		while (ob.top != NULL)
		{
			opr = ob.pop();
			p[i++] = opr;
		}
		i--;
		int len = strlen(p);
		len--;
		for (int i = 0; len >= 0; i++, len--)
		{
			q[i] = p[len];
		}
		cout<<q;
	}

	int priority(char c)
	{
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/' || c == '%')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return 0;
	}
};

int main()
{
	char str[50], pqr[50];
	postfix OB;
	cout << "Enter the infix expression : ";
	cin >> str;
	//cout << str;
	int len = strlen(str);
	len--;
	for (int i = 0; len >= 0; i++, len--)
	{
		pqr[i] = str[len];
	}
	OB.set_exp(pqr);
	cout << "\nPrefix expression is : ";
	OB.convert();
	return 0;
}
/*************************************************
OUTPUT:
it@IT-PL-5:~/Desktop$ g++ conv_prefix1.cpp
it@IT-PL-5:~/Desktop$ ./a.out
Enter the infix expression : (a+b^c)*d+e^5

Prefix expression is : +*+a^bcd^e5it@IT-PL-5:~/Desktop$
********************************/


