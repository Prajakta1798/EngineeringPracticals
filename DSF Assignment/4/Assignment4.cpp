/*Assignment No:4                                                                                            Roll_no.
Title:Construct and expression tree from postfix/prefix expression and perform recursive and  non- recursive In-order, pre-order and post-order traversals.
--------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<string.h>
using namespace std;
class Node
{
public:
    char data;
    Node *left,*right;
};
struct stacknode
{
    Node *data;
    //int flag=0;
};
class Stack
{
    Node *data[30],*t;
    int top,st;
    char ch[30];
public:
    Stack()
    {
        top=-1;
    }
    void push_n(Node *t)
    {
        data[++top]=t;
    }
    Node *pop_n()
    {
        return(data[top--]);
    }
    int isempty()
    {
        if(top==-1)
            return(1);
        else
            return(0);
    }
    Node *create();
    void preorder_nr(Node *t);
    void inorder_nr(Node *t);
    void postorder_nr(Node *t);
    void preorder(Node *t);
    void inorder(Node *t);
    void postorder(Node *t);
};
Node* Stack::create()
{
    cout<<"\nEnter the postfix expression:\n";
    cin>>ch;
    int len=strlen(ch);
    for(int i=0;i<len;i++)
    {
        if(isalnum(ch[i]))
        {
            Node *newn=new Node();
            newn->data=ch[i];
            newn->left=NULL;
            newn->right=NULL;
            push_n(newn);
        }
        else
        {
            Node *t1,*t2;
            t2=pop_n();
            t1=pop_n();
            Node *newn=new Node();
            newn->data=ch[i];
            newn->left=t1;
            newn->right=t2;
            push_n(newn);
        }
    }
    t=pop_n();
    return t;
}

void Stack::preorder_nr(Node *t)
{
	while(t!=NULL)
	{
		cout<<t->data;
		push_n(t);
		t=t->left;
	}
	while(!isempty())
    {
        t=pop_n();
        t=t->right;
        while(t!=NULL)
        {
            cout<<t->data;
            push_n(t);
            t=t->left;
        }
    }
}
void Stack::inorder_nr(Node *t)
{
	while(t!=NULL)
	{
		push_n(t);
		t=t->left;
	}
	while(!isempty())
    {
        t=pop_n();
        cout<<t->data;
        t=t->right;
        while(t!=NULL)
        {
            push_n(t);
            t=t->left;
        }
    }
}
void Stack::preorder(Node *t)
{
		if(t!=NULL)
		{
			cout<<t->data;
			preorder(t->left);
			preorder(t->right);
		}
}
void Stack::inorder(Node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data;
		inorder(t->right);
	}
}
void Stack::postorder(Node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<t->data;
	}
}
void Stack::postorder_nr(Node *t)
{
    int i=0;
char str[20];
while(!isempty()||t!=NULL)
{
while(t!=NULL)
{
str[i++]=t->data;
push_n(t);
t=t->right;
}
t=pop_n();
t=t->left;
}
while(--i>=0)
cout<<str[i];


}
int main()
{
    Stack s;
    int ch,ch1,ch2;
    Node *t;
    do
    {
        cout<<"\n***MENU***\n1.Create\n2.Display tree traversal\n3.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: t=s.create();
                    break;
            case 2: cout<<"\n1.Recursive\n2.Non-Recursive\nEnter choice:";
                    cin>>ch2;
                    switch(ch2)
                    {
                        case 1:
                                cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\nEnter choice: ";
                                cin>>ch1;
                                switch(ch1)
                                {
                                    case 1: s.preorder(t);
                                            break;
                                    case 2: s.inorder(t);
                                            break;
                                    case 3: s.postorder(t);
                                            break;
                                }
                                break;
                        case 2:
                                cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\nEnter choice: ";
                                cin>>ch1;
                                switch(ch1)
                                {
                                    case 1: s.preorder_nr(t);
                                            break;
                                    case 2: s.inorder_nr(t);
                                            break;
                                    case 3: s.postorder_nr(t);
                                            break;
                                }
                                break;
                    }
                    break;
            case 3: cout<<"\nExiting..";
                    break;
        }
    }
    while(ch!=3);
return(0);
}
/*------------------------------------------------------------------------------------------------
OUTPUT:
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 1
Enter the postfix expression:
abc-+
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 2
1.Recursive
2.Non-Recursive
Enter choice:1
1.Preorder
2.Inorder
3.Postorder
Enter choice: 1
+a-bc
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 2
1.Recursive
2.Non-Recursive
Enter choice:1
1.Preorder
2.Inorder
3.Postorder
Enter choice: 2
a+b-c
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 2
1.Recursive
2.Non-Recursive
Enter choice:1
1.Preorder
2.Inorder
3.Postorder
Enter choice: 3
abc-+
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 2
1.Recursive
2.Non-Recursive
Enter choice:2
1.Preorder
2.Inorder
3.Postorder
Enter choice: 1
+a-bc
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 2
1.Recursive
2.Non-Recursive
Enter choice:2
1.Preorder
2.Inorder
3.Postorder
Enter choice: 2
a+b-c
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 2
1.Recursive
2.Non-Recursive
Enter choice:2
1.Preorder
2.Inorder
3.Postorder
Enter choice: 3
abc-+
***MENU***
1.Create
2.Display tree traversal
3.Exit
Enter your choice: 3
Exiting..*/
