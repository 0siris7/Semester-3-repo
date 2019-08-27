#include <stdio.h>
#include<conio.h>
#include<math.h>
void linsearch(int a[],int n,int s)
{
     int i;
     for(i=0;i<n;i++)
     {
      if(a[i]==s)
      {
       printf("%d is present at location %d. \n",s,i+1);
       break;
      }
     }
     if(i==n)
      printf("%d not present in the array.",s);
}

void binsearch(int array[],int n,int search)
{
  int first,last,middle;
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
}
 void bubble(int array[],int n)
 {
     int i,j,temp;
     for(i=0;i<n;i++)
      {
         for(j=0;j<n-1-i;j++)
           {
               if(array[j]>array[j+1])
                 {
                   temp=array[j];
                   array[j]=array[j+1];
                   array[j+1]=temp;
                 }
           }
      }
      
 }
main()
{
   int array[100], search, c, n,ch;
   printf("Enter the size of array\n");
   scanf("%d",&n);
   printf("\nEnter the elements");
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);
   do
   {   
    printf("\nEnter the number to search\n");
    scanf("%d", &search);
    printf("\n1.Linear search\n");
    printf("2.Binary search\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1: {
              linsearch(array,n,search);
              break;        
             }
     case 2: {
              bubble(array,n);
              binsearch(array,n,search);
              break;
             }          
    
    }
    printf("\nDo you want to continue ? (Y=1 AND N=0): ");
    scanf("%d",&ch);
   }while(ch==1);
}
