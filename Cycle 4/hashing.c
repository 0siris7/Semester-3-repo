//Implementation of Hashing

#include<stdio.h>
#include<conio.h>

int main()
{
 int i,n,p,j;
 printf("Enter the Number of Items");
 scanf("%d",&n);
 int a[n];
 printf("Enter a Prime Number Greater than the Number of ITEMS");
 scanf("%d",&p);
 if(n>p)
 {
   getch();
   exit(0);
}
 // To insert elements into Array
 printf("\nEnter the Array Elements : ");
 for(i=0;i<n;i++)
 {
   scanf("%d",&a[i]);
 }
 int h[p];
 // Assigning 0 to newly desinged Array
 for (i=0;i<p;i++)
 {
   h[i]=0;
 }

 for (i=0;i<n;i++)
 {
     
      j=a[i]%p;
    
      if (h[j]==0)
      {
          h[j]=a[i];  
         
      }
      else
      {
          while(h[j]!=0)
          {
           
            if(j==p)
            {
                   j=0;
            }
            else 
            {
             j=j+1;
            }     
          }
        h[j]=a[i];
      }
          
     
 }
 
 // Printing Hashed Array
  for(i=0;i<p;i++)
  {
    if (h[i]!=0) 
    {
      printf("\n%d -> %d",i,h[i]);     
    }  
  }
    getch();  
}
