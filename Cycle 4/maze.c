// Implementation of MAZE problem using stack
#include<stdio.h>
#include<conio.h>
int flag=0;

void adjacentcellcheck(int m[7][7],int visit[7][7],int stai,int staj,int endi,int endj)
{
     if((stai>=0&&stai<=6)&&(staj>=0&&staj<=6))
     {                  
          if(visit[endi][endj]==0&&m[endi][endj]==0)
          {
                  visit[endi][endj]=1;
                  if(endi==endi&&endj==endj)
                        flag=1;
                  adjacentcellcheck(m,visit,endi-1,endj-1,endi,endj);
                  adjacentcellcheck(m,visit,endi-1,endj,endi,endj);
                  adjacentcellcheck(m,visit,endi-1,endj+1,endi,endj);
                  adjacentcellcheck(m,visit,endi,endj-1,endi,endj);
                  adjacentcellcheck(m,visit,endi,endj+1,endi,endj);
                  adjacentcellcheck(m,visit,endi+1,endj-1,endi,endj);
                  adjacentcellcheck(m,visit,endi+1,endj,endi,endj);                                                                                    
                  adjacentcellcheck(m,visit,endi+1,endj+1,endi,endj);
           }
           else
                  return;
            
     }
}
int main()
{
   int i,j,stai,staj,endi,endj;
   int m[7][7]={{1,1,0,1,0,1,1},{1,0,1,1,0,0,0},{1,1,0,1,0,1,1},{1,1,0,0,1,0,1},{0,1,1,1,0,1,1},{0,0,1,0,0,0,0},{1,0,1,0,0,0,0}};
  
   // The Check Matrix  
   int visit[7][7];  
   for(i=0;i<7;i++)
     {
        for(j=0;j<7;j++) 
        {  
           printf("\t %d",m[i][j]);
        }
        printf("\n ");
     }
   for(i=0;i<7;i++)
     {
        for(j=0;j<7;j++) 
        {  
           visit[i][j]=0;
        }
      
     }
  
   printf("\nEnter The Adress Of Starting And Ending Location ");
   printf("\nEnter Starting  i:");
   scanf("%d",&stai);
   printf("\nEnter Starting  j:");
   scanf("%d",&staj);
   printf("\nEnter stop i:");
   scanf("%d",&endi);
   printf("\nEnter stop j:");
   scanf("%d",&endj);
   
   adjacentcellcheck(m,visit,stai,staj,endi,endj);
   if(flag==0)
         printf("\n\t NO Path Exist !!! ");      
    else
         printf("\n\t Path Exists !!!");
   getch();
}
