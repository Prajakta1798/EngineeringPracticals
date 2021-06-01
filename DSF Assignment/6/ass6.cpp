#include<iostream>
#include<string.h>
#define MAX 20
#define TRUE 1
#define FALSE 0
using namespace std;

class graph
{
private:
        typedef struct node1
        {
                int vertex;
                int no_of_comments;
                char birthdate[40];
                struct node1 *next;
        }node;

        node *head[MAX];

        struct friendList
        {
                int no_of_friends;
                int no_of_comments;
                char birthdate[40];
        }friends[MAX];

        int visited[20];
        int Q[MAX],front,rear;

        public:
                graph();
                void create();
                void bfs(int);
};


graph::graph()
{
int v1;

for(v1=0;v1< MAX;v1++)
        visited[v1]=FALSE;

front=rear=-1;

for(v1=0;v1<MAX;v1++)
        head[v1]=NULL;

}

void graph::create()
{

int v1,v2,c;
char ans = 'y';
node *New, *first;

cout<<"\n\n Enter the vertices no.beginning with 0";
do
{

        cout<<"\n Enter the edge of graph \n";
        cin>>v1>>v2;

        if(v1>=MAX || v2>=MAX)
        cout<<"Invalid vertex value\n";

        else
        {
                New=new node;
                if(New==NULL)
                        cout<<"Insuff Mem\n";

                New->vertex=v2;
                New->next=NULL;
                first = head[v1];

                if(first==NULL)
                        head[v1]=New;
                else
                {
                        while(first->next!=NULL)
                                first=first->next;
                        first->next=New;
                }

                New=new node;

                if(New==NULL)
                        cout<<"Insuff Mem \n";
                New->vertex=v1;
                New->next=NULL;
                first=head[v2];

                if(first==NULL)
                        head[v2]=New;
                else
                {
                        while(first->next!=NULL)
                                first=first->next;
                        first->next=New;
                }

                cout<<"\n Enter no.of comments for V"<<v1<<":";
                cin>>c;
                head[v1]->no_of_comments=c;

                cout<<"\n Enter Birth Date(dd-mm-yyyy) for v"<<v1<<":";
                cin>>head[v1]->birthdate;

                cout<<"\n Enter no.of comments for V"<<v2<<":";
                cin>>c;
                head[v2]->no_of_comments=c;

                cout<<"\n Enter Birth Date(dd-mm-yyyy)for V"<<v2<<":";
                cin>>head[v2]->birthdate;
        }

        cout<<"\n Do you want to add nore edges?(y/n)";
        cin>>ans;
}while(ans=='y');

}

void graph::bfs(int v1)
{
int i,no_of_friends,n,max_friends,friend_node,choice;
int max_comments, min_comments;
char ans='y';
char month[3],extract_month[MAX][3];

node *first;

Q[++rear]=v1;

while(front!=rear)
{
        i=Q[++front];
        if(visited[i]==FALSE)
        {
                visited[i]=TRUE;
        }

        first=head[i];

        friends[i].no_of_comments=head[i]->no_of_comments;
        strcpy(friends[i].birthdate,head[i]->birthdate);
        no_of_friends=0;

        while(first!=NULL)
        {
                if(visited[first->vertex]==FALSE)
                {
                        Q[++rear]=first->vertex;
                }
                first=first->next;
                no_of_friends++;

        }

        friends[i].no_of_friends = no_of_friends;
}

n=i;
cout<<"\n User's_Node\tNo.Of Friends\tNo.ofComments\t Birth Date";
cout<<"\n ----------------------------------------------------------";
for(i=0;i<=n;i++)
{
        cout<<"\n" <<i<<"\t\t"<<friends[i].no_of_friends<<"\t\t"<<friends[i].no_of_comments<<"\t\t"<<friends[i].birthdate;

}

cout<<"\n -----------------------------------------------------------";
do
{
cout<<"\n\n\t\tMenu";
cout<<"\n1.Find who has max friends";
cout<<"\n2.Find who has post max comments";
cout<<"\n3.Find who has post min comments";
cout<<"\n4.Enter the month to display birthdate";
cout<<"\n Enter you choice";
cin>>choice;

switch(choice)
{
        case 1: friend_node= 0;
                max_friends=friends[0].no_of_friends;

        for(i=0;i<=n;i++)
        {
                if(max_friends < friends[i].no_of_friends)
                {
                        max_friends=friends[i].no_of_friends;
                        friend_node=i;
                }
        }


        cout<<"\n The node "<<friend_node<<" has max friends = "<<max_friends;
        break;

        case 2: friend_node= 0;
                max_comments=friends[0].no_of_comments;

        for(i=0;i<=n;i++)
        {
                if(max_comments < friends[i].no_of_comments)
                {
                        max_comments=friends[i].no_of_comments;
                        friend_node=i;
                }
        }


        cout<<"\n The node "<<friend_node<<" has max comments = "<<max_comments;
        break;

        case 3:  friend_node= 0;
              min_comments=friends[0].no_of_comments;

        for(i=0;i<=n;i++)
        {
                if(min_comments > friends[i].no_of_comments)
                {
                        min_comments=friends[i].no_of_comments;
                        friend_node=i;
                }
        }


        cout<<"\n The node "<<friend_node<<" has min comments = "<<min_comments;
        break;


        case 4: cout<<"\n Enter the month";
                cin>>month;

                for(int j=0;j<MAX;j++)
                {
                        extract_month[j][0]=friends[j].birthdate[3];
                        extract_month[j][1]=friends[j].birthdate[4];
                        extract_month[j][2]='\0';
                }

                cout<<"\n Displaying user's having birthday in this month";

                for(i=0;i<=n;i++)
                {
                        if(strcmp(month,extract_month[i])==0)
                        {
                                cout<<"\n User node"<<i;
                        }
                }
                break;
}

cout<<"\n Do you want to go to main menu?(y/n)";
cin>>ans;
}while(ans=='y' || ans=='Y');
}

int main()
{

int v1;
graph gr;
graph();
gr.create();
cout<<"\n Enter vertex from which you want to traverse";
cin>>v1;
if(v1>=MAX)
        cout<<"\n Invalid Vertex";
else
{
        cout<<"\n The BFS of Graph is \n";
        gr.bfs(v1);
        return 0;
}
}

