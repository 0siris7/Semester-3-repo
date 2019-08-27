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

int main()
{
     int i,n,p=0,r,a[50];
     printf("Enter size of array:"); 
     scanf("%d",&n);                
     r=n;                           
     printf("\nEnter array:");   
     for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      
     mergesort(a,p,r);
     printf("\nSorted array:");
     display(a,n);
     
     getch();
     
    
}
















