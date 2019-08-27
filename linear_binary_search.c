#include<stdio.h>
#include<conio.h>

void b_search(int a[],int u,int l)
{    printf("\nEnter item to be searched:");
     
     int key;
     scanf("%d",&key);
     
     int mid=(u+l)/2;
     while(l<=u)
      {
        
        if(key==a[mid])
         {
           
           printf("\n%d Found at %d th location",key,mid+1);
           break;
         }
        else if(key<a[mid])
          {u=mid-1;
          }
        else
         {l=mid+1;
         }
        mid=(u+l)/2;
      }
      if(l>u)
       {
        printf("\n element Not found");
       }
      return;

}

 void l_search(int a[],int size)
 {               printf("\nenter element to be searched:");
                 int key;
                 scanf("%d",&key);
                 int i;
                 for(i=0;i<size;i++)
                  {
                    if(key==a[i])
                     {           
                                 printf("%d found at %d th location",key,i+1);
                     }
                   
                    
                   
                  }
                  
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
      
 }
 
void display(int a[],int n)
{
     int i;
     for(i=0;i<n;i++)
      {
          printf(" %d ",a[i]);
      }
}

void main()
{
int a[50],b[50],i,size;
fflush(stdin);
printf("Enter size of array:");
scanf("%d",&size);
printf("\nEnter array:");
for(i=0;i<size;i++)
 {
  scanf("%d",&a[i]);
  b[i]=a[i];
 }
 
l_search(a,size);
bubble(b,size);
printf("\nAfter sorting:");
display(b,size);
b_search(b,size-1,0);
getch();
}
