#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
struct ll
{
       int c,e;
          
       struct ll *link;
};
void display(struct ll *header)
{
     struct ll *temp;
     temp=(struct ll*)malloc(sizeof(struct ll));
     temp=header;
     printf("\n");
     if(header!=NULL)
     {
     while(temp!=NULL)
     {
                      printf(" %dX^%d + ",temp->c,temp->e);
                      temp=temp->link;
     }
     }
     if(header==NULL)
          printf("Linked list is NULL");
}
struct ll* read(struct ll *p)
{
       char ch='y';
       int c,e;
       struct ll *temp,*newnode;
             
       while(ch!='n')
       {
                      newnode=(struct ll*)malloc(sizeof(struct ll));    
                      newnode->link=NULL; 
                     printf("\nEnter the coefficient value:");
                     scanf("%d",&c);
                     printf("\nEnter the exponent:");
                     scanf("%d",&e);
                     newnode->c=c;
                     newnode->e=e;
                     newnode->link=NULL;
                     if(p->link==NULL)
                     {
                                           p->link=newnode;                                          
                                           temp=newnode;
                                           
                     }
                     else
                     {
                         temp->link=newnode;
                         temp=newnode;
                       
                     }                  
                       printf("%d",newnode->c);  
                     printf("Do you want to coninue(y/n):");
                     fflush(stdin);
                     scanf("%c",&ch);
       }
       
       display(p->link);
       printf("\n");
       return(p);  
}

void destroy(struct ll *header)
{
     struct ll *temp;
     temp=(struct ll*)malloc(sizeof(struct ll));
     while(header!=NULL)
     {
                        temp=header;
                        header=header->link;
                        free(temp);
     }
     free(header);
}                   
struct ll* mult(struct ll *a,struct ll *b)
{      int c,e;
       struct ll *ptr,*temp,*r,*p,*q;
       r=(struct ll*)malloc(sizeof(struct ll));
       p=(struct ll*)malloc(sizeof(struct ll));
       q=(struct ll*)malloc(sizeof(struct ll));
       temp=(struct ll*)malloc(sizeof(struct ll));
       r=NULL;
       p=a;
       q=b;
       while(p!=NULL)
       {             
                     q=b;
                     while(q!=NULL)
                     {
                                   c=(p->c)*(q->c);
                                   e=(p->e)+(q->e);
                                   if(r==NULL)
                                   {
                                              ptr=(struct ll*)malloc(sizeof(struct ll));
                                              ptr->c=c;
                                              ptr->e=e;
                                              ptr->link=NULL;
                                              r=ptr;
                                   }
                                   else
                                   {
                                       temp=r;
                                       while(temp!=NULL)
                                       {
                                                        if(temp->e==e)
                                                         {
                                                         temp->c=temp->c+c;     
                                                         break;
                                                         }
                                                         else
                                                        temp=temp->link;
                                       }
                                       
                                      if(temp==NULL)
                                      {
                                       
                                              ptr=(struct ll*)malloc(sizeof(struct ll));
                                              ptr->c=c;
                                              ptr->e=e;
                                              ptr->link=NULL; 
                                              temp=r;
                                              while(temp->link!=NULL)
                                              temp=temp->link;
                                              temp->link=ptr;
                                       }
                                   }
                                   q=q->link;
                            }                 
                            p=p->link;
       }   
       return r;
}                     
      
int main()
{
     struct ll *a,*b,*r;
     a=(struct ll*)malloc(sizeof(struct ll));
     b=(struct ll*)malloc(sizeof(struct ll));
     r=(struct ll*)malloc(sizeof(struct ll));
     a->link=NULL;
     b->link=NULL;
     r->link=NULL;
     printf("\n Enter the polynomial(1):");
     a=read(a);
     printf("\n Enter the polynomial(2):");
     b=read(b);
     printf("The result is \n");
     r=mult(a->link,b->link);
     display(r);
     getch();
     destroy(a);
     destroy(b);
     destroy(r);
}                                            
