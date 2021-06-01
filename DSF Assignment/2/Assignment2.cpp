/*
ASSIGNMENT NO.2
		Implement priority queue as ADT using single linked list for servicing patients in an hospital
		with priorities as i) Serious (top priority) ii) medium illness (medium priority) iii) General (Least
		priority).
sss

*/


#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
	public:
		int id,P;
		char name[50];
		node *next;
};

class Patient
{
	public:
		node *head;
		Patient()
		{
			head=NULL;
		}
		void enqueue();
		void dequeue();
		void display();
};

void Patient::enqueue()
{
	node *newn;
	node *q;
	newn= new node();
	q=head;
	cout<<"\n Enter the id of patient:";
	cin>>newn->id;
	cout<<"\n Enter the name of patient:";
	cin>>newn->name;
	cout<<"\n Enter the priority(0,1,2)";
	cin>>newn->P;
	newn->next=NULL;

	if(head==NULL)
	{
		head=newn;
		return;
	}
	else if(newn->P>head->P)
	{
		newn->next=head;
		head=newn;
	}
	else
	{
		q=head;
		while(q->next!=NULL && newn->P<q->P)
		{
			q=q->next;
			newn->next=q->next;
		}
	}
}
void Patient::display()
{
	node *t;
	t=head;
	while(t!=NULL)
	{
		cout<<"\n\t Id"<<"\t Name"<<"\t Priority:";
		while(t!=NULL)
		{
			cout<<"\n\t  "<<t->id<<"\t  "<<t->name<<"\t   "<<t->P;
			t=t->next;
		}
	}
}
void Patient::dequeue()
{
	node *t=head;
	if(t!=NULL)
	{
        delete(t);
		head=head->next;
    }
	else
	{
        cout<<"Queue is empty:";
    }
}
int main()
{
	int ch;
	Patient p;

	do
	{
		cout<<"\n1.Entry \n2.Display \n3.Delete \n4.Exit\nEnter  your choice: ";
		cin>>ch;
	switch(ch)
	{
	case 1:

		cout<<"\nEnter the deatils of Patient:";
		p.enqueue();
		break;

	case 2:
		cout<<"\nDisplay details:";
		p.display();
		break;

	case 3:
		cout<<"Exit of Patient:";
		p.dequeue();
		break;

	}
	}while(ch!=4);
return 0;
}
/*----------------------------------------------------------------------------------------
Output:


1.Entry
2.Display
3.Delete
4.Exit
Enter  your choice: 1

Enter the deatils of Patient:
 Enter the id of patient:1

 Enter the name of patient:abc

 Enter the priority(0,1,2)1

1.Entry
2.Display
3.Delete
4.Exit
Enter  your choice: 1

Enter the deatils of Patient:
 Enter the id of patient:2

 Enter the name of patient:xyz

 Enter the priority(0,1,2)2

1.Entry
2.Display
3.Delete
4.Exit
Enter  your choice: 2

Display details:
         Id      Name    Priority:
          2       xyz      2
          1       abc      1
1.Entry
2.Display
3.Delete
4.Exit
Enter  your choice: 3
Exit of Patient:
1.Entry
2.Display
3.Delete
4.Exit
Enter  your choice: 2

Display details:
         Id      Name    Priority:
          1       abc      1
1.Entry
2.Display
3.Delete
4.Exit
Enter  your choice: 4

--------------------------------------------------------------------------------------------------*/
