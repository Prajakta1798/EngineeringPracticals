#include<stdio.h>
void read(int mat[10][10],int r,int c);//function prototype
void display(int mat[10][10],int r,int c);//function prototype
void add(int mat1[10][10],int mat2[10][10],int r,int c,int mat3[10][10]);//function prototype
void multi(int mat1[10][10],int mat2[10][10],int r1,int c1,int r2,int c2,int mat4[10][10]);//function prototype
void trans(int mat1[10][10],int r,int c,int mat5[10][10]);//function prototype


main()
{
 int mat1[10][10],mat2[10][10],mat3[10][10],mat4[10][10],mat5[10][10],mat6[10][10];
 int r1,c1,r2,c2,ch,ch2;
    do
   {



        printf("\n1.Enter the matrices ::\n2.Display elements of two matrices\n3.Addition of two matrices\n4.Multiplication of two matrices\n5.Transpose of two matrice\n6.Exit");

      printf("\nEnter your choice ::");
    scanf("%d",&ch);


    switch(ch)
   {

       case 1:
        printf("\nEnter row size and column size of matrix 1");
      scanf("%d%d",&r1,&c1);
      printf("\nEnter elements of matrix 1\n");
      read(mat1,r1,c1);
      printf("\nEnter row size and column size of matrix 2");
      scanf("%d%d",&r2,&c2);
      printf("\nEnter elements of matrix 2\n");
      read(mat2,r2,c2);



    case 2:
	  printf("\nMatrix1 is :\n");
      display(mat1,r1,c1);
      printf("\nMatrix2 is :\n");
      display(mat2,r2,c2);
      break;
    case 3:
        printf("Addition of two matrices is:\n");
        add(mat1,mat2,r1,c1,mat3);
      break;
    case 4:
           printf("\nMultiplication of two matrices is:\n");
           multi(mat1,mat2,r1,c1,r2,c2,mat4);
                 break;
    case 5:
         printf("\nThe transpose of matrix1 is:\n");
         trans(mat1,r1,c1,mat5);
         printf("\nThe transpose of matrix2 is:\n");
         trans(mat2,r2,c2,mat6);

       break;

   }
  }while(ch>0 && ch<6);

}
void read(int mat[10][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d",&mat[i][j]);
    }
  }
}
void display(int mat[10][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("%d\t",mat[i][j]);
    }
    printf("\n");
  }
}
void add(int mat1[10][10],int mat2[10][10],int r,int c,int mat3[10][10])
{
  int i,j;
  for(i=0;i<r;i++)
  {
     for(j=0;j<c;j++)
     {
        mat3[i][j]=mat1[i][j]+mat2[i][j];
     }
  }
   display(mat3,i,j);
}
void multi(int mat1[10][10],int mat2[10][10],int r1,int c1,int r2,int c2,int mat4[10][10])
{
  int i,j,sum=0,k;
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c2;j++)
    {
       sum=0;
     for(k=0;k<c1;k++)
     {
      sum=sum+mat1[i][k]*mat2[k][j];
     }
       mat4[i][j]=sum;
    }
  }
  display(mat4,i,j);
}
void trans(int mat[10][10],int r,int c,int mat5[10][10])
{
  int i,j;
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
    {
       mat5[i][j]=mat[j][i];
    }
  }
  display(mat5,i,j);
}
