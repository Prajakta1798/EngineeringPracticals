#include<iostream>

#define infinity 9999
#define max 10
using namespace std;
class graph
{
        int g[max][max];
        int n;
        public:
        graph()
        {
        n=0;
        }
        void create();
        void display();
        int min(int a,int b);
        void warshall();
};

void graph::create()
{
        int i,j;
        cout<<"\nEnter the number of Cities:";
        cin>>n;
        cout<<"\nThe Cost of the Cities:";
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        cin>>g[i][j];
                        if(i==j)
                        g[i][j]=0;
                }
        }
}

void graph::display()
{
        int i,j;

        for(i=1;i<=n;i++)
        {
 		 cout<<"\n";
                for(j=1;j<=n;j++)
                {
                        cout<<"\t"<<g[i][j];
                }
        }
}


int graph::min(int a,int b)
{
        if(a<b)
                return a;
        else
                return b;
}

void graph::warshall()
{
        int i,j,k;
        int R[3][10][10];

        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        R[0][i][j]=g[i][j];
                }
        }

        for(k=1;k<=n;k++)
        {
                for(i=1;i<=n;i++)
                {
                        for(j=1;j<=n;j++)
                        {
		 R[k][i][j]=min(R[k-1][i][j],R[k-1][i][k]+R[k-1][k][j]);
                        }
                }
        }

        

for(k=0;k<=n;k++)
{
	cout<<"\nk="<<k;
        for(i=1;i<=n;i++)
        {
                
                cout<<"\n";
                for(j=1;j<=n;j++)
                {
                        cout<<"\t"<<R[k][i][j];
                }
        }
cout<<"\n\n";
}


}
main()
{
        graph g1;
        int u,ch;
        char ans1;
        do
        {
                cout<<"\n MENU:";
                cout<<"\n1.CREATE\n2.DISPLAY\n3.WARSHALL";
                cout<<"\nEnter Your Choice:";
    cin>>ch;
                switch(ch)
                {
                        case 1: g1.create();
                                break;
                        case 2: g1.display();
                                break;
                        case 3: g1.warshall();
                                break;
                        default :cout<<"\nWrong choice";
                                break;
               }
        cout<<"\nDo you want to continue:";
        cin>>ans1;
        }while(ans1=='y'||ans1=='Y');
}
/***********OUTPUT*************

cclab-29@cclab29-OptiPlex-3010:~$ cd Desktop
cclab-29@cclab29-OptiPlex-3010:~/Desktop$ g++ ass10.cpp
cclab-29@cclab29-OptiPlex-3010:~/Desktop$ ./a.out

 MENU:
1.CREATE
2.DISPLAY
3.WARSHALL
Enter Your Choice:1

Enter the number of Cities:4

The Cost of the Cities:
0 8 999 1
999 0 1 999
4 999 0 999
999 2 9 0

Do you want to continue:y

 MENU:
1.CREATE
2.DISPLAY
3.WARSHALL
Enter Your Choice:2

	0	8	999	1
	999	0	1	999
	4	999	0	999
	999	2	9	0
Do you want to continue:y

 MENU:
1.CREATE
2.DISPLAY
3.WARSHALL
Enter Your Choice:3

k=0
	0	8	999	1
	999	0	1	999
	4	999	0	999
	999	2	9	0


k=1
	0	8	999	1
	999	0	1	999
	4	12	0	5
	999	2	9	0


k=2
	0	8	9	1
	999	0	1	999
	4	12	0	5
	999	2	3	0


k=3
	0	8	9	1
	5	0	1	6
	4	12	0	5
	7	2	3	0


k=4
	0	3	4	1
	5	0	1	6
	4	7	0	5
	7	2	3	0


Do you want to continue:n
cclab-29@cclab29-OptiPlex-3010:~/Desktop$ */

