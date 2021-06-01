#include<stdio.h>
#include<string.h>
struct Student
{
        int rno;
        char name[10];
        char city[10];
        int cont;
}s[5];
void read(struct Student s[5],int n);
void display(struct Student s[5],int n);
void add(struct Student s[5],int n,int addno);
void search(struct Student s[5],int n,int rno);
void modify(struct Student s[5],int n,int rno);
int main()
{
        int n,ch,i,rno,addno;
        do
        {
                printf("\n1.Read data\n2.Display data\n3.Add data\n4.Search data\n5.Modify data\n6.Exit");
                printf("\nEnter your choice =>");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                                printf("\nEnter the no. of students ::");
                                scanf("%d",&n);
                                read(s,n);
                                break;
                        case 2:
                                printf("\nThe details of students is as follows:");
                                display(s,n);
                                break;
                        case 3:
                                printf("\nEnter details to add to database ::");
                                printf("\nEnter no of students to add ::");
                                scanf("%d",&addno);
                                add(s,n,addno);
                                n=n+addno;
                                break;
                        case 4:
                                printf("\nEnter the roll no to search ::");
                                scanf("%d",&rno);
                                search(s,n,rno);
                                break;
                        case 5:
                                printf("\nEnter the roll no to modify ::");
                                scanf("%d",&rno);
                                modify(s,n,rno);
                                break;

                }
        }while(ch>0 && ch<6);
}
void read(struct Student s[5],int n)
{
        int i;
        for(i=0;i<n;i++)
        {
          printf("\nEnter roll no:\n");
          scanf("%d",&s[i].rno);
          printf("\nEnter name:\n");
          scanf("%s",&s[i].name);
          printf("\nEnter city:\n");
          scanf("%s",s[i].city);
          printf("\nEnter contact no:\n");
          scanf("%d",&s[i].cont);
        }
}
void display(struct Student s[5],int n)
{
        int i;
                printf("\nRollno\tName  \tCity   \tContact no\n");
     for(i=0;i<n;i++)
     {
       printf("  %d    \t%s    \t%s    \t%d\n",s[i].rno,s[i].name,s[i].city,s[i].cont);
      }
}
void add(struct Student s[5],int n,int addno)
{
        int i;
        for(i=n;i<n+addno;i++)
        {
                printf("\nEnter roll no\n");
                scanf("%d",&s[i].rno);
                printf("\nEnter name\n");
                scanf("%s",&s[i].name);
                printf("\nEnter city\n");
                scanf("%s",s[i].city);
                printf("\nEnter contact no\n");
                scanf("%d",&s[i].cont);
        }
}
void search(struct Student s[5],int n,int rno)
{
        int i=0,flag=0;
        for(i=0;i<n;i++)
        {
           if(s[i].rno==rno)
           {
               flag=1;
               printf("\nData found\n");
               printf("\nRollno\tName  \tCity   \tContact no\n");
               printf("  %d    \t%s    \t%s     \t%d\n",s[i].rno,s[i].name,s[i].city,s[i].cont);
               break;
             }
                else
                {
                        flag=0;
                }
        }
        if(flag==0)
        printf("\nData not found for Roll no %d\n",rno);
}
void modify(struct Student s[5],int n,int rno)
{
 int i=0,flag=0,ch;
        for(i=0;i<n;i++)
        {
                if(s[i].rno==rno)
                {
                  printf("\nRecords found\n");
                        flag=1;
                        break;
                }
       }

        if(flag==1)
        {
         do
         {
          printf("\n1.Roll no\n2.Name\n3.City\n4.Contact no\n5.MENU");
          printf("\nEnter the Roll No to change the data. %d:",rno);
          scanf("%d",&ch);
          switch(ch)
         {
           case 1:
                        printf("\nEnter roll no ::\n");
                        scanf("%d",&s[i].rno);
                        break;
         case 2:
                     printf("\nEnter name ::\n");
                      scanf("%s",&s[i].name);
                      break;
        case 3:
                      printf("\nEnter city ::\n");
                      scanf("%s",s[i].city);
                      break;
        case 4:
                     printf("\nEnter contact no ::\n");
                        scanf("%d",&s[i].cont);
                        break;
          }
      }while(ch>0 && ch<5);
   }
   else
   printf("\nData not found for Roll No. %d",rno);
}
