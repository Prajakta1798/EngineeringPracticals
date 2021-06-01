#include<iostream>
#include<exception>
using namespace std;
class exception1
{
private:
double a,b;
public:
void read_double();
void divide();
};
void exception1::read_double()
{
try
{
cout<<"\n enter value of a=";
cin>>a;
if(cin.fail())
{
throw 'a';
}
cout<<"\nenter value of b=";
cin>>b;
if(cin.fail())
{
throw 'b';
}
}
catch(char c)
{
cout<<"\n exception caught\n";
cout<<"\n invalid value of 'a' & 'b'\n";
}
}
void exception1::divide()
{
try{
if(b==0)
{
throw 1;
}
else
{
cout<<"\n division="<<a/b<<"\n";
}
}
catch(int m)
{
cout<<"\n divide by zero error\n";
}
}
int main()
{
exception1 e;
e.read_double();
e.divide();
return 0;
}

