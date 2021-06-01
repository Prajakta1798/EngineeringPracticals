/*ASSIGNMENT NO:11
TITLE:

*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class student
{
        typedef struct stud
        {
                char name[10];
                int rollno;
                char div;
                char add[30];
        }rec;
        rec record;
        public:
        void create();
        void display();
        int search(int r);
        void update(int r);
        void delete1(int r);
        void append();
};


/********************************************
FUNCTION NAME=create() 
INPUT PARAMETER=none
OUTPUT PARAMETER=none
FUNCTION CALLED=main
FUNCTION CALLING=none
DESCRIPTION=to create the element
******************************************/
void student::create()
{
        char ans;
        fstream f;
        f.open("abc.txt",ios::in|ios::out|ios::binary);
        do
        {
                cout<<"Enter Student Name:";
                cin>>record.name;
                cout<<"Enter Student Roll No:";
                cin>>record.rollno;
                cout<<"Enter Student Division:";
                cin>>record.div;
                cout<<"Enter Student Address:";
                cin>>record.add;
                f.write((char*)&record,sizeof(record));
                cout<<"\nDo you add more Information:";
                cin>>ans;
        }while(ans=='y');
        f.close();
}

/********************************************
FUNCTION NAME=display()
INPUT PARAMETER=none
OUTPUT PARAMETER=none
FUNCTION CALLED=main
FUNCTION CALLING=none
DESCRIPTION=to display the element
******************************************/
void student::display()
{
        fstream f;
        f.open("abc.txt",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        cout<<"\n Content Of Files Are:";
	cout<<"\n\nName\tRoll no   \tDivision\tAddress";
	cout<<"\n-----------------------------------------------";
        while(f.read((char*)&record,sizeof(record)))
        {
                if(record.rollno!=-1)
                {
                        cout<<"\n"<<record.name;
                        cout<<"\t"<<record.rollno;
                        cout<<"\t\t"<<record.div;
                        cout<<"\t\t"<<record.add;
                }
                else
                {
                        cout<<"\nYou Entered Wrong Roll No";
                }
        }
        f.close();
}

/********************************************
FUNCTION NAME=update() 
INPUT PARAMETER=roll no
OUTPUT PARAMETER=none
FUNCTION CALLED=main
FUNCTION CALLING=none
DESCRIPTION=to update a element
******************************************/
void student::update(int r)
{
        fstream f;
        f.open("abc.txt",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        int pos=search(r);
        if(pos==-1)
        {
                cout<<"\nRecord Not Found";
                return;
        }
        int offset=pos*(sizeof(rec));
        f.seekp(offset);
                        cout<<"\nEnter New Data:";
                        cout<<"\nEnter Student Name:";
                        cin>>record.name;
                        cout<<"\nEnter Student Roll No:";
                        cin>>record.rollno;
                        cout<<"\nEnter Student Division:";
                        cin>>record.div;
                        cout<<"\nEnter Student Address:";
                        cin>>record.add;
        f.write((char*)&record,sizeof(record));
        f.seekg(0);
        f.close();
        cout<<"\nRecord Updated";
}

/********************************************
FUNCTION NAME=delete1() 
INPUT PARAMETER=roll no
OUTPUT PARAMETER=none
FUNCTION CALLED=main
FUNCTION CALLING=none
DESCRIPTION=to delete the element
******************************************/
void student::delete1(int r)
{
        fstream f;
        f.open("abc.txt",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        int pos=search(r);
        if(pos==-1)
        {
                cout<<"\nRecord Not Found";
                return;
        }
        int offset=pos*(sizeof(rec));
        f.seekp(offset);
        //f.clear();
                        strcpy(record.name," ");
                        record.rollno=-1;
                        record.div='\0';
                        strcpy(record.add," ");
        f.write((char*)&record,sizeof(record));
        f.seekg(0);
        f.close();
        cout<<"\nRecord Deleted";
}

/********************************************
FUNCTION NAME=append() 
INPUT PARAMETER=none
OUTPUT PARAMETER=none
FUNCTION CALLED=main
FUNCTION CALLING=none
DESCRIPTION=to append or add the element
******************************************/
void student::append()
{
        fstream f;
        f.open("abc.txt",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        int i=0;
        while(f.read((char*)&record,sizeof(record)))
        {
                i++;
        }
        f.clear();
         cout<<"\nEnter New Data:";
         cout<<"\nEnter Student Name:";
         cin>>record.name;
         cout<<"\nEnter Student Roll No:";
         cin>>record.rollno;
         cout<<"\nEnter Student Division:";
         cin>>record.div;
         cout<<"\nEnter Student Address:";
                        cin>>record.add;
        f.write((char*)&record,sizeof(record));
        f.seekg(0);
        f.close();
        cout<<"\nRecord Added";
}

/********************************************
FUNCTION NAME=search() 
INPUT PARAMETER=none
OUTPUT PARAMETER=none
FUNCTION CALLED=main
FUNCTION CALLING=none
DESCRIPTION=to search the elements
******************************************/
int student::search(int r)
{
        fstream f;
        int pos,i;
        f.open("abc.txt",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        cout<<"\nINFORMATION OF STUDENT IS :";
        for(i=0;i<10;i++)
        {
        while(f.read((char*)&record,sizeof(record)))
        {
                if(record.rollno==r)
                {
                        cout<<"\nStudent Name:"<<record.name;
                        cout<<"\nStudent Roll No:"<<record.rollno;
                        cout<<"\nStudent Division:"<<record.div;
                        cout<<"\nStudent Address:"<<record.add;
                        pos=i;
                        break;
                }
                i++;
        }
        }
        cout<<"\n"<<pos;
        f.close();
        return pos;
}

main()
{
        student s;
        char ans1;
        int r;
        int ch;
        do
        {
                cout<<"\n MENU:";
                cout<<"\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.UPDATE\n5.DELETE\n6.APPEND";
 cout<<"\nEnter Your Choice:";
                cin>>ch;
                switch(ch)
                {
                        case 1: s.create();
                                break;
                        case 2: s.display();
                                break;
                        case 3:cout<<"Enter The Roll No To Search:";
                               cin>>r;
                               s.search(r);
                               break;
                        case 4:cout<<"Enter The Roll No To Update:";
                               cin>>r;
                               s.update(r);
                               break;
                        case 5:cout<<"Enter The Roll No To Delete:";
                               cin>>r;
                               s.delete1(r);
                               break;
                        case 6: s.append();
                                break;
                        default :cout<<"\nWrong choice";
                                break;
               }
        cout<<"\nDo you want to continue with menu(y/n):";
        cin>>ans1;
   }while(ans1=='y'||ans1=='Y');
}

/*OUTPUT:
cclab-29@cclab29-OptiPlex-3010:~$ cd Desktop
cclab-29@cclab29-OptiPlex-3010:~/Desktop$ cd dsf
cclab-29@cclab29-OptiPlex-3010:~/Desktop/dsf$ g++ ass11.cpp
cclab-29@cclab29-OptiPlex-3010:~/Desktop/dsf$ ./a.out

 MENU:
1.CREATE
2.DISPLAY
3.SEARCH
4.UPDATE
5.DELETE
6.APPEND
Enter Your Choice:1
Enter Student Name:anushri
Enter Student Roll No:73  
Enter Student Division:A
Enter Student Address:sghdhg

Do you add more Information:y
Enter Student Name:varsha
Enter Student Roll No:64
Enter Student Division:A
Enter Student Address:nfhjhgjk

Do you add more Information:y
Enter Student Name:shailaja
Enter Student Roll No:67
Enter Student Division:B
Enter Student Address:trugtfh

Do you add more Information:n

Do you want to continue with menu(y/n):y

 MENU:
1.CREATE
2.DISPLAY
3.SEARCH
4.UPDATE
5.DELETE
6.APPEND
Enter Your Choice:2

 Content Of Files Are:

Name	Roll no   	Division	Address
-----------------------------------------------
anushri	73		A		sghdhg
varsha	64		A		nfhjhgjk
shailaja	67		B		trugtfh
jkj	55		d		jkbnkj
Do you want to continue with menu(y/n):y

 MENU:
1.CREATE
2.DISPLAY
3.SEARCH
4.UPDATE
5.DELETE
6.APPEND
Enter Your Choice:3
Enter The Roll No To Search:73

INFORMATION OF STUDENT IS :
Student Name:anushri
Student Roll No:73
Student Division:A
Student Address:sghdhg
0
Do you want to continue with menu(y/n):y

 MENU:
1.CREATE
2.DISPLAY
3.SEARCH
4.UPDATE
5.DELETE
6.APPEND
Enter Your Choice:4
Enter The Roll No To Update:67

INFORMATION OF STUDENT IS :
Student Name:shailaja
Student Roll No:67
Student Division:B
Student Address:trugtfh
2
Enter New Data:
Enter Student Name:shelo

Enter Student Roll No:76

Enter Student Division:A

Enter Student Address:fhgjhfk

Record Updated
Do you want to continue with menu(y/n):y

 MENU:
1.CREATE
2.DISPLAY
3.SEARCH
4.UPDATE
5.DELETE
6.APPEND
Enter Your Choice:5
Enter The Roll No To Delete:76

INFORMATION OF STUDENT IS :
Student Name:shelo
Student Roll No:76
Student Division:A
Student Address:fhgjhfk
2
Record Deleted
Do you want to continue with menu(y/n):y

 MENU:
1.CREATE
2.DISPLAY
3.SEARCH
4.UPDATE
5.DELETE
6.APPEND
Enter Your Choice:6

Enter New Data:
Enter Student Name:shelo

Enter Student Roll No:67

Enter Student Division:b

Enter Student Address:hdgffhj

Record Added
Do you want to continue with menu(y/n):n*/
