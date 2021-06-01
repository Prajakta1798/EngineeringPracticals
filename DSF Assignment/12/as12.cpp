/*************************************************
Assignment # 12
Implement direct access file using hashing (chaining without replacement) perform following operations on it.
a. Create Database
b. Display Database
c. Add a record
d. Search a record
e. Modify a record

Name: Nikam Priyanka Karbhari
Roll No.: 35
Class: SE IT
***************************************************/

#include<iostream>
#include<fstream>

using namespace std;
#define TableSize 10

class DAFile
{
	private:
		struct stud
		{
			int rno;
			char name[TableSize];
			int chain;
		};
	public:
	DAFile();
	int hash(int);
	void display();
	void create();
	void addrecord();
	int search(int);
	void modify();
};

DAFile::DAFile()
{
}

void DAFile::create()
{
	stud r;
	int i;
	ofstream fs;
	r.rno=-1;
	r.name[0]='\0';
	r.chain=-1;
	//Initialize all locations
	fs.open("master.dat",ios::binary|ios::out);
	if(fs)
	{
		for(i=0;i<TableSize;i++)
		{
			fs.seekp((i)*sizeof(r),ios::beg);
			fs.write((char*)&r, sizeof(r));
		}
		cout<<"File created successfully!\n";
	}
	else
		cout<<"\nUnable to Open File for writing!";
}
void DAFile::display()
{
	ifstream fs;
	stud r;
	char ch;
	fs.open("master.dat",ios::binary|ios::in);
	if(fs)
	{
		cout<<"\nRollno\tname\tchain\n";
		while(fs.read((char*)&r, sizeof(r)))
		{
			cout<<"\n"<<r.rno<<"\t"<<r.name<<"\t"<<r.chain;
		}
	}
	else
		cout<<"\nUnable to Open File for reading!";
	fs.close();

}
int DAFile::hash(int rollno)
{
	return(rollno % TableSize);
}


void DAFile::addrecord()
{
	fstream fs;
	stud r,m;
	int index,index1;
	char ch;
	fs.open("master.dat",ios::binary|ios::in|ios::out);
	do
	{
	 	cout<<"\nEnter roll no. and name of student: ";
	 	cin >> r.rno;
	 	cin >> r.name;
	 	r.chain =-1;
	 	index=hash(r.rno);
	 	//Go to the index location and check for empty slot
	 	fs.seekg((index)*sizeof(r),ios::beg);
	 	fs.read((char*)&m, sizeof(m));
	 	if(m.rno==-1)
	 	{  //Empty slot found
			fs.seekp((index)*sizeof(r),ios::beg);
			fs.write((char*)&r, sizeof(r));
	 	}
	 	else
	 	{
			//no empty slot
			//Traverse the chain
			while(m.chain!=-1)
			{
				index=m.chain;
				fs.seekg((index)*sizeof(r),ios::beg);
				fs.read((char*)&m, sizeof(m));
			}
	
			index1=index;
			//Apply linear probing technique
			do
			{
				index=(index+1)%TableSize;
				fs.seekg((index)*sizeof(r),ios::beg);
				fs.read((char*)&m, sizeof(m));
			}
			while((index!=index1)&&(m.rno!=-1));
			if(index==index1)
			{
				cout<<"\nOverflow!! Cannot add the Record.";
				break;
			}
			else
			{
				//write the record at the empty postion
				fs.seekp((index)*sizeof(r),ios::beg);
				fs.write((char*)&r, sizeof(r));
				//Update the chain
				fs.seekg((index1)*sizeof(r),ios::beg);
				fs.read((char*)&m, sizeof(m));
				if(hash(m.rno)==hash(r.rno))
					m.chain=index;
				else
					m.chain=-1;
				fs.seekp((index1)*sizeof(r),ios::beg);
				fs.write((char*)&m, sizeof(m));
			}
		}
		cout<<"Record Added.\n";
	 	cout<<"\nWould you like to add another Record? (y/n) ";
		cin>>ch; 
	}
	while(ch=='Y'||ch=='y');
	fs.close();
	display();
}

int DAFile::search(int rno)
{
	ifstream fs;
	stud r,m;
	int i,index,index1,flag=0;
	char ch;

	fs.open("master.dat",ios::binary|ios::in);
	if(fs)
	{
		index=hash(rno);
	 	//Go to the index location and check for empty slot
	 	fs.seekg((index)*sizeof(m),ios::beg);
	 	fs.read((char*)&m, sizeof(m));
	 	if(m.rno==rno)
	 	{  //Record found
			flag=1;
	 	}
	 	else
	 	{
          		if(hash(rno)==hash(m.rno))
          		{	//Synonym, Traverse the chain
		   		while((m.chain!=-1)&&(hash(rno)==hash(m.rno)))
		   		{
					index=m.chain;
					fs.seekg((index)*sizeof(m),ios::beg);
					fs.read((char*)&m, sizeof(m));
					if(m.rno==rno)
					{
						flag=1;
						break;
					}
		   		}//end of while
           		}//end of inner if
          		else
          		{
		   		index1=index;
				//Apply linear probing technique
		 		do
				{
					index=(index+1)%TableSize;
					fs.seekg((index)*sizeof(m),ios::beg);
					fs.read((char*)&m, sizeof(m));
				}
				while((index!=index1)&&(m.rno!=rno));
	     		}//end of inner else
	  	}//end of outer else   
		if((index!=index1)&&(m.rno==rno))
			flag=1;

		if(flag==0)
		{
			cout<<"\nRecord Not found!";
			index=-1;
		}
		else
		{
			cout<<"\nRecord Found at Location "<<index;
			fs.seekg((index)*sizeof(r),ios::beg);
			fs.read((char*)&r, sizeof(r));
			cout<<"\n"<<r.rno<<"\t"<<r.name;
		}
	}
	else
		cout<<"\nUnable to open the file for reading!";
	fs.close();
	return (index);
}

void DAFile::modify()
{
	fstream fs;
	stud r,m;
	int i,rno,index,index1;
	char ch;
	cout << "\nEnter roll no. to be modified: ";
	cin >> rno;

	index=search(rno);
	if(index==-1)
		cout<<"\nCan't modify";
	else
	{
		fs.open("master.dat",ios::binary|ios::in|ios::out);
		if(fs)
		{
			 //Go to the index location and check for empty slot
			fs.seekg((index)*sizeof(m),ios::beg);
			fs.read((char*)&m, sizeof(m));
			cout<<"\nEnter modified name of the student: ";
			cin >> m.name;
			fs.seekp((index)*sizeof(m),ios::beg);
			fs.write((char*)&m, sizeof(m));
			cout<<"Record Modified.\n";
		}
		else
			cout<<"\nUnable to open the file for modification!";

	}
	fs.close();
}

int main()
{   
	int choice,rno;
	char ch;
	DAFile file;
	do
	{
		cout<<"\n1.Create\n2.Add Record\n3.Modify Record\n4.Search Record";
		cout<<"\n5.Display Records\n6.Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: file.create();
				break;
			case 2: file.addrecord();
				break;
			case 3: file.modify();
				break;
			case 4: cout<<"Enter a roll no. to be searched: ";
				cin>>rno;
				file.search(rno);
				break;
			case 5: file.display();
				break;
		}
	}
	while(choice!=6);
}

/*****OUTPUT**********

bvcoew@bvcoew-Lenovo-S510:~$ cd Desktop/rn35
bvcoew@bvcoew-Lenovo-S510:~/Desktop/rn35$ g++ ass12.cpp
bvcoew@bvcoew-Lenovo-S510:~/Desktop/rn35$ ./a.out

1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 5

Unable to Open File for reading!
1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 1
File created successfully!

1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 2

Enter roll no. and name of student: 1 dipika 
Record Added.

Would you like to add another Record? (y/n) y

Enter roll no. and name of student: 2 Manasi
Record Added.

Would you like to add another Record? (y/n) y

Enter roll no. and name of student: 3 Dipali
Record Added.

Would you like to add another Record? (y/n) y

Enter roll no. and name of student: 4 Nisha
Record Added.

Would you like to add another Record? (y/n) y 

Enter roll no. and name of student: 5 Neha
Record Added.

Would you like to add another Record? (y/n) n

Rollno	name	chain

-1		-1
1	dipika	-1
2	Manasi	-1
3	Dipali	-1
4	Nisha	-1
5	Neha	-1
-1		-1
-1		-1
-1		-1
-1		-1
1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 5

Rollno	name	chain

-1		-1
1	dipika	-1
2	Manasi	-1
3	Dipali	-1
4	Nisha	-1
5	Neha	-1
-1		-1
-1		-1
-1		-1
-1		-1
1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 3

Enter roll no. to be modified: 6

Record Not found!
Can't modify

1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 3

Enter roll no. to be modified: 5

Record Found at Location 5
5	Neha
Enter modified name of the student: pooja
Record Modified.

1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 5

Rollno	name	chain

-1		-1
1	dipika	-1
2	Manasi	-1
3	Dipali	-1
4	nisha	-1
5	pooja	-1
-1		-1
-1		-1
-1		-1
-1		-1
1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 4
Enter a roll no. to be searched: 6

Record Not found!

1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 4
Enter a roll no. to be searched: 2

Record Found at Location 2
2	Manasi
1.Create
2.Add Record
3.Modify Record
4.Search Record
5.Display Records
6.Exit
Enter your choice: 6
bvcoew@bvcoew-Lenovo-S510:~/Desktop/rn35$ */

