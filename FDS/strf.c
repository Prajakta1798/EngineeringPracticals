#include<stdio.h>
void len(char str[20]);
void palindrome(char str[20]);
void compare(char str1[20],char str2[20]);
void copy(char str1[20],char str2[20]);
void rev(char str1[20],char str2[20]);
void substring(char str1[20],char str2[20]);
main()
{
char str1[20],str2[20];
  int ch;
   do{
        printf("\n1.Find the length of string\n2.Check whether string is palindrome or not\n3.Compare two strings\n4.Copy one string into other string\n5.Find reverse of a string\n6.Exit");
  printf("\nEnter your choice");
  scanf("%d",&ch);
 switch(ch)
 {
   case 1:
             printf("\nEnter the string whose length to calculate\n");
             scanf("%s",str1);
             len(str1);
             break;
  case 2:
             printf("\nEnter the string to check whether it is palindrome or not\n");
             scanf("%s",str1);
             palindrome(str1);
             break;
  case 3:
            printf("\nEnter the string 1\n");
            scanf("%s",str1);
            printf("\nEnter the string 2\n");
            scanf("%s",str2);
            compare(str1,str2);
            break;
  case 4:
            printf("\nEnter the string 1\n");
            scanf("%s",str1);
            printf("\nEnter the string 2\n");
            scanf("%s",str2);
            copy(str1,str2);
            break;
  case 5:
            printf("\nEnter the string to reverse\n");
            scanf("%s",str1);
            rev(str1,str2);
            break;
  case 6:
            printf("\nEnter the string 1\n");
            scanf("%s",str1);
            printf("\nEnter the string 2 to search as substring\n");
            scanf("%s",str2);
            substring(str1,str2);
            break;
   }
 }while(ch>0  &&  ch<7);
}void len(char str[20])
{
  int i=0;
  for(i=0;str[i]!='\0';i++);
  printf("\nThe length of %s is %d\n",str,i);
}
void palindrome(char str[20])
{
   int i=0,j=0,flag=0;
   for(i=0;str[i]!='\0';i++);
   i--;
   while(i>=0 && str[i]!='\0')
   {
        if(str[i]!=str[j])
       {
          flag=1;
          break;
       }
          i--;
          j++;
    }
     if(flag==1)
     printf("\nEntered string %s is not palindrome\n",str);
     else
     printf("\nEntered string %s is palindrome\n",str);
  }
void compare(char str1[20],char str2[20])
{
    int i=0,flag=0;
    while(str1[i]!='\0' && str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
          flag=1;
          break;
        }
      i++;
    }
    if(flag==0 && str1[i]=='\0' && str2[i]=='\0')
    printf("\nBoth the strings are equal\n");
    else
    printf("\nStrings are not equal\n");
 }
void copy(char str1[20],char str2[20])
{
    int i=0;
    while(str1[i]!='\0')
     {
          str2[i]=str1[i];
          i++;
     }
   str2[i]='\0';
   printf("\nCopied string is %s\n",str2);
}
void rev(char str1[20],char str2[20])
{
   int i=0,j=0;
   for(i=0;str1[i]!='\0';i++);
   i--;
   while(i>=0)
   {
        str2[j]=str1[i];
       j++;
       i--;
    }
    str2[j]='\0';
   printf("\nThe reverse of %s is %s\n",str1,str2);
 }
void substring(char str1[20],char str2[20])
{
   int i=0,j=0,flag=0;
   for(i=0;str1[i]!='\0';i++)
    {
        flag=0;
      for(j=0;str2[j]!='\0';j++)
      {
        if(str2[j]==str1[i])
        {
           flag=1;
           i++;
        }
         else
        {
          flag=0;
          break;
        }
      }
      if(str2[j]=='\0')
      break;
     }
    if(flag==1)
    printf("\nThe entered string %s is substring of %s\n",str2,str1);
    else
    printf("\nThe entered string %s is not substring of %s\n",str2,str1);
}

