/**************************************************************                                   					ASSIGNMENT NO:
ROLL NO:                                                                                   BATCH :
TITTEL:     Evalution of postfix expression.
*************************************************************/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#include"stack.h"

stack obj;
class posteval
{
public:
void calculate(char expr[10]);
int show();
};


void posteval::calculate(char expr[10])
{
int n1,n2,n3,n,len,i=0;
len=strlen(expr);
while(i<len)
{
	if(expr[i]== ' '||expr[i]== '\t')
	{
	continue;
	}

	else if(isdigit(expr[i]))
	{
		n=expr[i]-'0';
		obj.push(n);
	}
	else
	{
	n1=obj.pop();
	n2=obj.pop();
	switch(expr[i])
	{
	case '+':
	n3=n2+n1;
	break;
	case '-':
	n3=n2-n1;
	break;
	case '*':
	n3=n2*n1;
	break;
	case '/':
	n3=n2/n1;
	break;
	}
	obj.push(n3);
	}
i++;
}
}
int posteval::show()
{
int n;
n=obj.pop();
cout<<"poped value is"<<n;
}


int main()
{
  char expr[50];
  int ch,c;
  posteval p;
  do
  {
  cout<<"\n**********menu****************";
  cout<<"\n1:set experation";
  cout<<"\n2:calculate";
  cout<<"\n3:exit";
  cout<<"\nenter your choice";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"\nEnter postfix experssion :";
          cin>>expr;
          break;
   case 2:
         p.calculate(expr);
		c=p.show();
         break;
   case 3:cout<<"EXITING.............";
          break;
  }

} while(ch!=3);
}
/**************************************************************
OUTPUT:
**********menu****************
1:set experation
2:calculate
3:exit
enter your choice1

 enter experssion 653+9*+

**********menu****************
1:set experation
2:calculate
3:exit
enter your choice2
poped value is78
**********menu****************
1:set experation
2:calculate
3:exit
enter your choice3
it@IT-PL-5:~/Desktop/IT/Roll$ file:///home/it/Desktop/bst2.cpp

************************************************************/

