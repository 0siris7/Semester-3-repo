#include<stdio.h>
#include<conio.h>
#include<math.h>

void display(int a[],int n)
{int i;
     for(i=n;i>0;i--)
      {
                     printf(" %d ",a[i]);
      }
}
void merge(int a[],int p,int mid,int r)
{
     int b[50],i,j,k;
     k=0;
     i=p;
     j=mid+1;
     while(i<=mid&&j<=r)
      {
                        if(a[i]>a[j])
                         {
                                     b[k++]=a[i++];
                         }
                        else
                         {
                                     b[k++]=a[j++];
                         }
      }
    while(i<=mid)
     {
                 b[k]=a[i];
                 k++;
                 i++;
     }
     
    while(j<=r)
     {
               b[k]=a[j];
               k++;
               j++;
     }
    for(i=r;i>=p;i--)
     {
                     a[i]=b[--k];
     }
     
     
}
void mergesort(int a[],int p,int r)
{
     int mid;
     if(p<r)
      {
            mid=floor((p+r)/2);
            mergesort(a,p,mid);
            mergesort(a,mid+1,r);
            merge(a,p,mid,r);
            
      }
      
}

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

int main()
{
     int i,n,p=0,r,a[50],c[50];
     printf("Enter size of array:"); 
     scanf("%d",&n);
     r=n;
     printf("\nEnter array:");
     for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
          c[i]=a[i];
      }
      
     mergesort(a,p,r);
     printf("\nMerge Sorted array:");
     display(a,n);
     quicksort(c,0,n-1);
     printf("\nQuick sorted array:");
     for(i=0;i<n;i++)
      {
                     printf(" %d ",c[i]);
      }
     
     getch();
     
    
}

