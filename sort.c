#include<stdio.h>
#include<conio.h>
                                             
void display(int a[],int n)
{
     int i;
     for(i=0;i<n;i++)
      {
          printf(" %d ",a[i]);
      }
}

void insert(int a[],int n)
 {
   int i,j,key;
   for(i=1;i<n;i++)
    {                                                   
       key=a[i];                                                 
       j=i-1;
       while(j>=0&&a[j]>key)
         {
           a[j+1]=a[j];
           j=j-1;
         }
       a[j+1]=key;    
    }
    display(a,n);    
 }

void bubble(int a[],int n)
 {
     int i,j,temp;
     for(i=0;i<n;i++)
      {
         for(j=0;j<n-1-i;j++)
           {
               if(a[j]>a[j+1])
                 {
                   temp=a[j];
                   a[j]=a[j+1];
                   a[j+1]=temp;
                 }
           }
      }
      display(a,n);
 }
 
 void select(int a[],int n)
 {
      int i,j,temp;
      for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
          {
            if(a[i]>a[j])
              {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
              }
          
          }
      }
      display(a,n);
 }



int main()
{
     int i,n,a[50],b[50],c[50];
     printf("Enter size of array:");
     scanf("%d",&n);
     printf("\nEnter array:");
     for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      
      
      for(i=0;i<n;i++)
      {
          b[i]=a[i];
          c[i]=a[i];
      }
     
     printf("\nBubble sorted:");
     bubble(a,n);
     printf("\nInsertion sorted:");
     insert(b,n);
     printf("\nSelection sorted:");
     select(c,n);
     getch();
     return 0;
}




























