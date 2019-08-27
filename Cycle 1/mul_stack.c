#include<stdio.h>
#include<conio.h>
int push1(int s[],int top1,int top2,int item,int size)
    {
              if(top1>=(size-1) || top1>=(top2-1) )
                {
                    printf("\nSTACK 1 IS FULL\n");
                }
               
              else
               {
                    top1++;
                    s[top1]=item;
               }
               
               return top1;
    }      
    
    int push2(int s[],int top1,int top2,int item,int size)
    {
              if(top2<=0 || top2<=(top1+1))
                {
                    printf("\nSTACK 2 IS FULL\n");
                }
               
              else
               {
                    top2--;
                    s[top2]=item;
               }
               
               return top2;
    }      
    
    
  int pop1(int s[],int top1,int size)
    {         int item=0;
              if(top1<0)
               {
                       printf("\nSTACK 1 IS EMPTY\n");
                }
                
               else
                { item=s[top1];
                  top1--;
                }
               return top1;
    }
    
    int pop2(int s[],int top2,int size)
    {         int item=0;
              if(top2>=size)
               {
                       printf("\nSTACK 2 IS EMPTY\n");
                }
                
               else
                { item=s[top2];
                  top2++;
                }
               return top2;
    }
    
   void status(int s[],int top1,int top2,int size)               
     {     int i=0;
                   if(top1<0)
                    {
                            printf("\nSTACK 1 IS EMPTY\n");
                    }
                   
                   else
                    {   printf("\nSTACK1:");
                            for(i=top1;i>=0;i--)
                             {
                                              printf(" %d ",s[i]);
                             }
                    }
                    
                   
                   if(top2>=size)
                     {
                                 printf("\nSTACK 2 IS EMPTY");
                     }
                     
                   else
                    {      printf("\nSTACK2:");
                                 for(i=top2;i<=size-1;i++)
                                  {
                                     printf(" %d ",s[i]);
                                     }
                    }
                                 
                                 
     } 
     
      
   

int main()
 {
  int s[100],top1=-1,top2,ch=0,item,size;
  printf("enter size of stack:");
  scanf("%d",&size);
  top2=size;
  while(ch!=6)
   {
        printf("\n\nSTACK\n");
        printf("\n1.PUSH1");
        printf("\n2.POP1");
        printf("\n3.PUSH2");
        printf("\n4.POP2");
        printf("\n5.STATUS");
        printf("\n6.exit\n");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        
        switch(ch)
         {
                  case 1:
                          printf("\nenter item:");
                          scanf("%d",&item);
                          top1=push1(s,top1,top2,item,size);
                          status(s,top1,top2,size);
                          break;
                          
                  case 2:
                          top1=pop1(s,top1,size);
                          status(s,top1,top2,size);
                          break;
                          
                  case 3:
                          printf("\nenter item:");
                          scanf("%d",&item);
                          top2=push2(s,top1,top2,item,size);
                          status(s,top1,top2,size);
                          break;   
                  
                  
                          
                  case 4:
                          top2=pop2(s,top2,size);
                          status(s,top1,top2,size);
                          break;
                  
                  case 5:
                          status(s,top1,top2,size);
                          break;
                          
         
                          
                                            
         }
 
 
 
   }
 
    getch();
    return 0;
    
 } 
 
 
 
 
         
