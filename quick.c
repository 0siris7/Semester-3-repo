#include<stdio.h>
#include<conio.h>

void swap(int *a,int *b)
{
     int t=*a;
     *a=*b;
     *b=t;
}

int partition(int a[],int low,int high) 
{
    int i,j,pivot;
    pivot=a[high];
    i=(low-1);
    for(j=low;j<=high-1;j++)
     {
       if(a[j]<=pivot)
        {
          i++;
          swap(&a[i],&a[j]);
        }
     }
     swap(&a[i+1],&a[high]);
     return(i+1);
}


void quicksort(int a[],int low,int high) 
{
 if(low<high)
  {
             int p=partition(a,low,high);
             
             quicksort(a,low,p-1);
             quicksort(a,p+1,high);
  }     
}


void main()
{
     int i,n,a[50];
     printf("enter size of array:");
     scanf("%d",&n);                
     printf("\nenter array:");     
     for(i=0;i<n;i++)               
      {
                     scanf("%d",&a[i]);
      }
      
      quicksort(a,0,n-1);
      printf("\nSorted array:");
      for(i=0;i<n;i++)
      {
                     printf(" %d ",a[i]);
      }
      
      getch();
      
}














