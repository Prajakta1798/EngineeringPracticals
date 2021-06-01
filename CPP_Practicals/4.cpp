#include<iostream>
#include<string.h>
#define SIZE 10
using namespace std;
class PersonDB;
class Base1
{
protected:
char name[20];
char dob[20];
char bldGrp[4];
};
class Base2
{
protected:
int height, weight;
};
class Base3
{
protected:
char ipNum[20], address[20];
};
class Person : public Base1, public Base2, public Base3
{
protected:
char teleNum[20], drvLscNum[20];
public:
void set();
void disp();
friend class PersonDB;
};
void Person :: set()
{
cout<<"\n Enter name : ";
cin>>name;
cout<<"Enter dob(dd/mm/yyyy) : ";
cin>>dob;
cout<<"Enter blood group : ";
cin>>bldGrp;
cout<<"Enter Height(in cm) : ";
cin>>height;
cout<<"Enter Weight(in kg) : ";
cin>>weight;
cout<<"Enter Insurance Pol. Num(IP ******): IP ";
cin>>ipNum;
cout<<"Enter Contact Address (City) : ";
cin>>address;
cout<<"Enter telephone number(**********) : ";
cin>>teleNum;
cout<<"Enter driving liscence number(******) : ";
cin>>drvLscNum;
}
ostream& myformat(ostream &o)
{
o.setf(ios::left); //data on left
return o;
}
void Person ::disp()
{
cout<<myformat<<this->name<<"\t";
cout<<myformat<<this->dob<<"\t";
cout<<myformat<<bldGrp<<"\t";
cout<<myformat<<height<<"\t";
cout<<myformat<<weight<<"\t";
cout<<myformat<<ipNum<<"\t";
cout<<"\t"<<myformat<<address<<"\t";
cout<<myformat<<"\t"<<teleNum<<"\t\t";
cout<<myformat<<drvLscNum<<"\n";
}
class PersonDB
{
Person tbl[SIZE];
int n;
int isBuilt;
public:
PersonDB();
void build();
void add();
void dispAll();
void search();
void modify();
void del();
};
PersonDB::PersonDB()
{
isBuilt = 0;//false
}
void PersonDB :: build()
{
char ch;
n = 0;
isBuilt = 1;//true
do
{
if(n < SIZE)
{
tbl[n].set();
n++;
}
else
{
cout<<"\n Table is FULL ";
}
cout<<"\n\nWant to enter more record (y/n) : ";
cin>>ch;
}
while(ch=='y');
}
void PersonDB :: add()
{
if(isBuilt == 0)
{
cout<<"\n Build the table first ";;
return;
}
if(n < SIZE)
{
tbl[n].set();
n++;
}
else
{
cout<<"\n Table is FULL ";
}
}
void PersonDB :: dispAll()
{
if(isBuilt == 0)
{
cout<<"\n Build the table first ";;
return;
}
int i;
cout<<"-------------------------------------------------------------------------------------------------"<<"\n";
cout<<myformat<<"Name"<<"\t";
cout<<myformat<<"D_O_B"<<"\t\t";
cout<<myformat<<"BdGp"<<"\t";
cout<<myformat<<"Hght"<<"\t";
cout<<myformat<<"Wght"<<"\t";
cout<<myformat<<"IP Num"<<"\t";
cout<<myformat<<"\t"<<"Address"<<"\t\t";
cout<<myformat<<"Tele Num"<<"\t";
cout<<myformat<<"DrvLcNo"<<"\n";
cout<<"\n-----------------------------------------------------------------------------------------------"<<"\n";
for(i =0; i< n; i++)
{
tbl[i].disp();
}
}
void PersonDB :: search()
{//seq search
if(isBuilt == 0)
{
cout<<"\n Build the table first ";;
return;
}
char x[20];
int i;
int flag = 0;
cout<<"\n enter name to search : ";
cin>>x;
//sequential search
for(i =0; i< n; i++)
{
if(strcmp(tbl[i].name, x)==0)
{
tbl[i].disp();
flag = 1;
break;
}
}
if(flag == 0)
{
cout<<"\n"<<x<<" not found ";
}
}//search
void PersonDB :: modify()
{
if(isBuilt == 0)
{
cout<<"\n Build the table first ";;
return;
}
char x[20];
int i;
int flag = 0;
cout<<"\n enter name of record to modify : ";
cin>>x;
//sequential search
for(i =0; i< n; i++)
{
if(strcmp(tbl[i].name, x)==0)
{
tbl[i].disp();
cout<<"\n\n enter new data : ";
tbl[i].set();
flag = 1;
break;
}
}
if(flag == 0)
{
cout<<"\n"<<x<<" not found ";
}
}
void PersonDB :: del()
{
if(isBuilt == 0)
{
cout<<"\n Build the table first ";;
return;
}
char x[20];
int i;
int flag = 0;
cout<<"\n enter name of record to delete : ";
cin>>x;
//sequential search
for(i =0; i< n; i++)
{
if(strcmp(tbl[i].name, x)==0)
{
tbl[i].disp();
cout<<"\n\n record deleted ";
//shift the records one pos left
int j;
for(j =i; j<n; j++)
{
tbl[j] = tbl[j+1];
}
n--; //reduce size
flag = 1;
break;
}
}
if(flag == 0)
{
cout<<"\n"<<x<<" not found ";
}
}
int main()
{
//clrscr();
PersonDB pdb;
int ch;
do
{
//clrscr();
cout<<"\n 1. Build a master table";
cout<<"\n 2. List a table ";
cout<<"\n 3. Insert a new entry ";
cout<<"\n 4. Delete old entry ";
cout<<"\n 5. Edit an entry";
cout<<"\n 6. Search for a record ";
cout<<"\n 7. exit ";
cout<<"\n\n enter choice : ";
cin>>ch;
switch(ch)
{
case 1:
pdb.build();
break;
case 2:
pdb.dispAll();
break;
case 3:
pdb.add();
break;
case 4:
pdb.del();
break;
case 5:
pdb.modify();
break;
case 6:
pdb.search();
break;
case 7:
cout<<"\n\n!!! Thank You !!!";
break;
default:
cout<<"\n\n!!! Wrong Choice !!!";
}
cout<<"\n\n**** Press any key to continue ****";
}while(ch != 7);
return 0;
}
