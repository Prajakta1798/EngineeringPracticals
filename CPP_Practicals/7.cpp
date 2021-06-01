#include<iostream>
using namespace std;
template<class T>
class matrix
{
T x[3][3];
public:
void getdata(int r,int c);
void getdata1(int r,int c);
void getdata2(int r,int c);
void display(int r,int c);
void displaym(int r,int c);
void add(matrix <T>,int r,int c);
void sub(matrix <T>,int r,int c);
void mul(matrix <T>,matrix <T>,int r,int c);
};
template<class T>
void matrix<T>::getdata(int r,int c)
{
int i,j;
cout<<"\nEnter data of Matrix:-";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cout<<"\nEnter Data for location["<<i<<"]""["<<j<<"]";

cin>>x[i][j];
}
}
}
template<class T>
void matrix<T>::getdata1(int r,int c)
{
int i,j;
cout<<"\nEnter data of Matrix:-";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cout<<"\nEnter Data for location["<<i<<"]""["<<j<<"]";
cin>>x[i][j];
}
}
}
template<class T>
void matrix<T>::getdata2(int r,int c)
{
int i,j;
cout<<"\nEnter data of Matrix:-";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cout<<"\nEnter Data for location["<<i<<"]""["<<j<<"]";
cin>>x[i][j];
}
}
}
template<class T>
void matrix<T>::display(int r,int c)
{
int i,j;
cout<<"\nGiven Matrix Data is as Follows:-";
for(i=0;i<r;i++)
{
cout<<"\n";
for(j=0;j<c;j++)
{
cout<<"\t"<<x[i][j];
}
}
}
template<class T>
void matrix<T>::displaym(int r,int c)
{
int i,j;
cout<<"\nMultiplication of Given Matrix Data is as Follows:-";
for(i=0;i<r;i++)
{
cout<<"\n";
for(j=0;j<c;j++)
{
cout<<"\t"<<x[i][j];
}
}
}
template<class T>
void matrix<T>::add(matrix <T> b,int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
x[i][j]=x[i][j] + b.x[i][j];
}
}
}
template<class T>
void matrix<T>::sub(matrix <T> b,int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
x[i][j]=x[i][j]-b.x[i][j];
}
}
}
template<class T>
void matrix<T>::mul(matrix <T> a,matrix <T> b,int r,int c)
{
int i,j,k;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
x[i][j]=0;
}
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
for(k=0;k<r;k++)
{
x[i][j]=x[i][j]+(a.x[i][k]*b.x[k][j]);
}
}
}
}
int main()
{
matrix <int> m1,m2,m3;
int ch,rw,cl,mrw1,mrw2,mcl1,mcl2;;
while(1)
{
cout<<"\n1.Insert Matrix data";
cout<<"\n2.Display Matrix";
cout<<"\n3.Add the Matrix";
cout<<"\n4.Subtraction of Matrix";
cout<<"\n5.Multiplication of Matrix";
cout<<"\n6.Exit";
cout<<"\nEnter u r choice:-";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter size of matrix(row and coloum)";
cin>>rw>>cl;
m1.getdata(rw,cl);
m2.getdata(rw,cl);
break;
case 2:
m1.display(rw,cl);
m2.display(rw,cl);
break;
case 3:
m1.add(m2,rw,cl);
m1.display(rw,cl);
break;
case 4:
m1.sub(m2,rw,cl);
m1.display(rw,cl);
break;
case 5:
cout<<"\nEnter size of first matrix(row and coloum)";
cin>>mrw1>>mcl1;
cout<<"\nEnter size of second matrix(row and colum)";
cin>>mrw2>>mcl2;
if(mrw1==mcl2)
{
m1.getdata1(mrw1,mcl1);
m2.getdata2(mrw2,mcl2);
m3.mul(m1,m2,mrw1,mcl2);
m3.displaym(mrw1,mcl2);
}
else
{
cout<<"\nNumber of rows is not equal to number of coloum";
}
break;
case 6:
return 0;
break;
}
}
}

