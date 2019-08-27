#include<stdio.h>
#include<conio.h>

int push(int [],int,int,int);
int pop(int [],int,int);
void status(int [],int);

int main()
 {
  int s[100],top=-1,ch=0,item,size;
  printf("enter size of stack:");
  scanf("%d",&size);
  while(ch!=4)
   {
        printf("\n\nSTACK\n");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.STATUS");
        printf("\n4.EXIT\n");
        scanf("%d",&ch);
        
        switch(ch)
         {
                  case 1:
                          printf("\nenter item:");
                          scanf("%d",&item);
                          top=push(s,top,item,size);
                          status(s,top);
                          break;
                  
                  case 2:
                          top=pop(s,top,size);
                          status(s,top);
                          break;
                  
                  case 3:
                          status(s,top);
                          break;
                          
                                            
         }
 
 
 
   }
 
    getch();
    return 0;
    
 } 
 
 
 
 int push(int s[],int top,int item,int size)
    {
              if(top>=(size-1))
                {
                    printf("\nSTACK IS FULL\n");
                }
               
              else
               {
                    top++;
                    s[top]=item;
               }
               
               return top;
    }      
    
    
    
  int pop(int s[],int top,int size)
    {         int item=0;
              if(top<0)
               {
                       printf("\nSTACK IS EMPTY\n");
                }
                
               else
                { item=s[top];
                  top--;
                }
               return top;
    }
    
   void status(int s[],int top)               
     {     int i=0;
                   if(top<0)
                    {
                            printf("\nSTACK IS EMPTY\n");
                    }
                   
                   else
                    {   printf("\nCURRENT STACK:");
                            for(i=top;i>=0;i--)
                             {
                                              printf(" %d ",s[i]);
                             }
                    }
     }            
