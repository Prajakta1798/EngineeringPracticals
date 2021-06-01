#include<iostream>
#include<string.h>
using namespace std;
class Book
{
public:
char Title[20],Author[20],Publisher[20];
int Price, Stock;
Book()
{
Price=Stock=0;
Title[0]=Author[0]=Publisher[0]='\0';
}
void accept();
void display();
void Modify(int n)
{
cout<<"\n Cost: "<<Price*n;
Stock+=n;
}
char* return_Title()
{
return Title;
}
};
void Book::accept()
{
cout<<"\nEnter Book Details:";
cout<<"\nTitle:";
cin>>Title;
cout<<"Author:";
cin>>Author;
cout<<"Publisher:";
cin>>Publisher;
cout<<"Price:";
cin>>Price;
cout<<"Stock:";
cin>>Stock;
}
void Book::display()
{
cout<<"\n"<<Title<<"\t\t"<<Author<<"\t\t"<<Publisher<<"\t\t"<<Price<<"\t\t"<<Stock;
}
class inventory:public Book
{
Book *B;
int No;
public:
inventory(int n=1)
{
B=new Book[n+5];
No=2;
}
void accept_Bookdata();
void display_Bookdata();
int Search(char[]);
void Purchase(char[]);
};
void inventory::accept_Bookdata()
{
for(int i=0;i<No;i++)
B[i].accept();
}
void inventory::display_Bookdata()
{
cout<<"\nBook Details";
cout<<"\n"<<Title<<"\t\t"<<Author<<"\t\t"<<Publisher<<"\t\t"<<Price<<"\t\t"<<Stock;
for(int i=0;i<No;i++)
B[i].display();
}
int inventory::Search(char T[20])
{
for(int i=0;i<No;i++)
{
if(strcmp(B[i].return_Title(),T)==0)
return i;
}
return -1;
}
void inventory::Purchase(char T[20])
{
int i=Search(T), St;
if(i==-1)
B[No++].accept();
else
{
cout<<"Enter number of copies to Purchase";
cin>>St;
B[i].Modify(St);
}
}
int main()
{
int ch,y;
inventory obj;
do
{
cout<<"\n1.Create"<<endl;
cout<<"2.Display"<<endl;
cout<<"3.Search"<<endl;
cout<<"4.Purchase"<<endl;
cout<<"5.Exit Program"<<endl;
cin>>ch;
switch(ch)
{
case 1:
obj.accept_Bookdata();
break;
case 2:
obj.display_Bookdata();
break;
case 3:
char x[20];
cout<<"Enter Title to search";
cin>>x;
y=obj.Search(x);
if(y==-1)
cout<<"Book not available";
else
cout<<"Book available in stock";
break;
case 4:
cout<<"Enter Title of book to purchase";
char a[20];
cin>>a;
obj.Purchase(a);
break;
case 5:
cout<<"End of Program";
break;
}
}while(ch!=5);
return 0;
}
