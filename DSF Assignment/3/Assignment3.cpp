/*
            ASSIGNMENT NO.3                                                                                    Roll_no.
Tile:Create Binary tree and perform following operations:
	a.Insert
	b.Display
	c.Depth of a tree
	d.Display leaf-nodes
	e.Create a copy of a tree
*/
#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
	public:
		int data;
		node *right,*left;
};

class binary
{
	public:

            node *create()
            {
                node *p;
                int x;

                cout<<"\nEnter the root data:";
                cin>>x;

                if(x==-1)
                {
                    return(NULL);
                }

                p=new node;
                p->data=x;

                cout<<"\nEnter the left child of root"<<x<<":";
                p->left=create();

                cout<<"\nEnter the right child "<<x<<":";
                p->right=create();
                return(p);
            }
            node *copy(node *root)
            {
                node *p;
                p=NULL;

                if(root!=NULL)
                {
                    p=new node;
                    p->data=root->data;
                    p->left=copy(root->left);
                    p->right=copy(root->right);
                   }
                return p;
            }
            void preorder(node *root);
            void inorder(node *root);
            void postorder(node *root);
            int height(node *root);
            int leaf_count(node *t);

};
//binary tree traversal;
void binary::preorder(node *root)
{

	if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void binary::inorder(node *root)
{

	if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void binary::postorder(node *root)
{
	if(root!=NULL)
     {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
     }
}
// height of tree
int binary::height(node *root)
{
	int hl,hr;

	if(root==NULL)
	{
		return 0;
	}

	if(root->left==NULL && root->right==NULL)
	{
		return 0;
	}
	else
	{
		hl=height(root->left);
		hr=height(root->right);

			if(hl>hr)
			{
				return(1+hl);
			}
			else
			{
				return(1+hr);
			}
	}

}
//counting of leaf node
int binary::leaf_count(node *root)
{
	int i;

	if(root==NULL)
        return(0);
	else if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";

    i=leaf_count(root->left)+leaf_count(root->right);
	return i;
}
//main program
int main()
{
    node *root,*p;
    int ch,ch1,a,q;
    binary b;
    do
    {
        cout<<"\n 1.Create binay tree \n 2.Display binary tree \n 3.Depth of tree \n 4.Display a leaf node \n 5.Create a copy of tree & display in preorder";
        cout<<"\n Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    root=b.create();
                    break;
            case 2:
                    cout<<"\n 1.Preorder \n 2.Inorder \n 3.Postorder";
                    cout<<"\n Enter your choice:";
                    cin>>ch1;
                    switch(ch1)
                    {
                        case 1:
                                cout<<"\nPreorder of binary tree: ";
                                b.preorder(root);
                                break;
                        case 2:
                                cout<<"\nInorder of binary tree: ";
                                b.inorder(root);
                                break;
                        case 3:
                                cout<<"\nPostorder of binary tree: ";
                                b.postorder(root);
                                break;
                    }
                    break;
            case 3:
                    q=b.height(root);
                    cout<<"\nHeight of binary tree:\t";
                    cout<<q+1;
                    break;
            case 4:
                    cout<<"\nLeaf nodes of binary tree:\t";
                    b.leaf_count(root);
                    break;
            case 5:
                    cout<<"\nCopy of binary tree: ";
                    p=b.copy(root);
                    b.preorder(p);
                    break;
            case 6:
                    cout<<"\nInvalid choice";
        }
    }while(ch!=6);
}
/*OUTPUT:

 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:1

Enter the root data:5

Enter the left child of root5:
Enter the root data:3

Enter the left child of root3:
Enter the root data:2

Enter the left child of root2:
Enter the root data:-1

Enter the right child 2:
Enter the root data:-1

Enter the right child 3:
Enter the root data:4

Enter the left child of root4:
Enter the root data:-1

Enter the right child 4:
Enter the root data:-1

Enter the right child 5:
Enter the root data:7

Enter the left child of root7:
Enter the root data:6

Enter the left child of root6:
Enter the root data:-1

Enter the right child 6:
Enter the root data:-1

Enter the right child 7:
Enter the root data:9

Enter the left child of root9:
Enter the root data:-1

Enter the right child 9:
Enter the root data:-1

 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:2

 1.Preorder
 2.Inorder
 3.Postorder
 Enter your choice:1

Preorder of binary tree: 5 3 2 4 7 6 9
 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:2

 1.Preorder
 2.Inorder
 3.Postorder
 Enter your choice:2

Inorder of binary tree: 2 3 4 5 6 7 9
 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:2

 1.Preorder
 2.Inorder
 3.Postorder
 Enter your choice:3

Postorder of binary tree: 2 4 3 6 9 7 5
 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:3

Height of binary tree:  3
 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:4

Leaf nodes of binary tree:      2 4 6 9
 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:5

Copy of binary tree: 5 3 2 4 7 6 9
 1.Create binay tree
 2.Display binary tree
 3.Depth of tree
 4.Display a leaf node
 5.Create a copy of tree & display in preorder
 Enter your choice:6

Invalid choice
*/


