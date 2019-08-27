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
     if(header!=NULL)
     {
     while(temp!=NULL)
     {
                      printf(" %dx%d + ",temp->c,temp->e);
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
                     printf("\nEnter the exponent :");
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
struct ll* add(struct ll *p,struct ll *q)
{
       struct ll *r,*rs,*temp;
       
       rs=(struct ll*)malloc(sizeof(struct ll));
       temp=(struct ll*)malloc(sizeof(struct ll));
       temp->link=NULL;
       rs->link=NULL;
       while((q!=NULL)&&(p!=NULL))
       {
                              r=(struct ll*)malloc(sizeof(struct ll));
                              r->link=NULL;
                              if((p->e)==(q->e))
                              {
                                            r->c=(q->c)+(p->c);
                                            r->e=q->e;
                                            q=q->link;
                                            p=p->link;
                              }
                              else if((p->e)>(q->e))
                              {
                                   r->c=p->c;
                                   r->e=p->e;
                                   p=p->link;
                              }
                              else if((p->e)<(q->e))
                              {
                                  r->c=q->c;
                                  r->e=q->e;
                                  q=q->link;
                              }
                              if(rs->link==NULL)
                              {
                                   rs->link=r;
                                   temp=r;
                              }
                              else
                              {
                                  temp->link=r;
                                  temp=r;
                              }
       }
       if(q!=NULL)
       {
                  while(q->link==NULL)
                  {
                                r=(struct ll*)malloc(sizeof(struct ll));
                                r->link=NULL;
                                r=q;
                                 q=q->link;
                                 temp->link=r;
                  }   r=(struct ll*)malloc(sizeof(struct ll));
                      r->link=NULL;
                      r=q;   
                      temp->link=r;             
       }                       
       if(p!=NULL)
       {
            while(p->link!=NULL)
            { 
                          r=(struct ll*)malloc(sizeof(struct ll));
                          r->link=NULL;
                          r=p;
                          p=p->link;
                          temp->link=r;
            }
            r=(struct ll*)malloc(sizeof(struct ll));
            r->link=NULL;
            r=p;   
            temp->link=r;             
       }              
return rs;
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
int main()
{
     struct ll *q,*p,*rs;
     p=(struct ll*)malloc(sizeof(struct ll));
     q=(struct ll*)malloc(sizeof(struct ll));
     rs=(struct ll*)malloc(sizeof(struct ll));
     q->link=NULL;
     p->link=NULL;
     rs->link=NULL;
     printf("\n Enter the first polynomial:");
     p=read(p);
     printf("\n Enter the second polynomial:");
     q=read(q);
     printf("The result is: \n");
     rs=add(p->link,q->link);
     display(rs->link);
     getch();
     destroy(p);
     destroy(q);
     destroy(rs);
}

     
       
       
       
       
       
       
       
       
