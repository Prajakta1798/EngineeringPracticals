#include<iostream>
#include<iomanip>
using namespace std;
class complex
{
float r,i;
public:
complex()
{
r=0;
i=0;
}
complex(int a,int b)
{
r=a;
i=b;
}
void display()
{
if(i<0)
cout<<endl<<setprecision(4)<<r<<i<<"i";
else
cout<<endl<<setprecision(4)<<r<<"+"<<i<<"i";
}
void get()
{
cout<<"\nFor a complex number : ";
cout<<"\nEnter the real part : ";
cin>>r;
cout<<"Enter the imaginary part : ";
cin>>i;
}
complex operator *(complex);
complex operator /(complex);
friend complex operator +(complex,complex);
friend complex operator -(complex,complex);
};
complex operator +(complex c1,complex c2)
{
complex c;
c.r= (c1.r+c2.r);
c.i= (c1.i+c2.i);
return c;
}
complex operator -(complex t1,complex t2)
{
complex c;
c.r= (t1.r-t2.r);
c.i= (t1.i-t2.i);
return c;
}
complex complex::operator *(complex t1)
{
complex t;
t.r=r*t1.r-i*t1.i;
t.i=r*t1.i+i*t1.r;
return t;
}
complex complex::operator /(complex t1)
{
complex t;
t.r=((r*t1.r)+(i*t1.i))/((t1.r*t1.r)+(t1.i*t1.i));
t.i=(-(r*t1.i)+(i*t1.r))/((t1.r*t1.r)+(t1.i*t1.i));
return t;
}
int main()
{
complex a,b,c,d;
int ch;
char ch2;
a.get();
a.display();
b.get();
b.display();
do{
cout<<"\n1)Add\n2)Subtract\n3)Multiply\n4) division \nEnter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
c=a+b;
cout<<"Addition : ";
c.display();
break;
case 2:
c=a-b;
cout<<"Subtraction : ";
c.display();
break;
case 3:
c=a*b;
cout<<"Multiplication : ";
c.display();
break;
case 4:
c=a/b;
cout<<"Division : ";
c.display();
break;
default:
cout<<"Invalid choice!";
break;
}
cout<<"\nDo you want to continue? (Y/N) : ";
cin>>ch2;
}while(ch2=='y'||ch2=='Y');
return 0;
}
