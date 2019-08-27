#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct node
{
       int c,e;
          
       struct node *link;
};
void display(struct node *header)
{
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
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
          printf("\nLinked list is NULL");
}

struct node *read_poly(struct node *header)
{
     
      char ch='y';
       int c,e;
       struct node *temp,*newnode;
             
       while(ch!='n')
       {
                     newnode=(struct node*)malloc(sizeof(struct node));    
                     newnode->link=NULL; 
                     printf("\nEnter the coefficient:");
                     scanf("%d",&c);
                     printf("\nEnter the exponent:");
                     scanf("%d",&e);
                     newnode->c=c;
                     newnode->e=e;
                     newnode->link=NULL;
                     if(header->link==NULL)
                     {
                                           header->link=newnode;                                          
                                           temp=newnode;
                                           
                     }
                     else
                     {
                         temp->link=newnode;
                         temp=newnode;
                       
                     }                  
                       printf("%d",newnode->c);  
                     printf("\nDo you want to coninue(y/n):");
                     fflush(stdin);
                     scanf("%c",&ch);
       }
       
       display(header->link);
       printf("\n");
       return(header);  
}
              
struct node* mult_poly(struct node *a,struct node *b)
{      int c,e;
       struct node *ptr,*temp,*r,*p,*q;
       r=(struct node*)malloc(sizeof(struct node));
       p=(struct node*)malloc(sizeof(struct node));
       q=(struct node*)malloc(sizeof(struct node));
       temp=(struct node*)malloc(sizeof(struct node));
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
                                              ptr=(struct node*)malloc(sizeof(struct node));
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
                                       
                                              ptr=(struct node*)malloc(sizeof(struct node));
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
 void destroy(struct node *header)
{
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     while(header!=NULL)
     {
                        temp=header;
                        header=header->link;
                        free(temp);
     }
     free(header);
}     

void main()
{
     
     struct node *a,*b,*r;
     a=(struct node*)malloc(sizeof(struct node));
     b=(struct node*)malloc(sizeof(struct node));
     r=(struct node*)malloc(sizeof(struct node));
     a->link=NULL;
     b->link=NULL;
     r->link=NULL;
     printf("\nenter first polynomial:");
     a=read_poly(a);
     printf("\nenter second polynomiial:");
     b=read_poly(b);
     r=mult_poly(a->link,b->link);
     printf("The resultant polynomial:");
     display(r);
     destroy(r);
     destroy(a);
     destroy(b);
     getch();
}
     

     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
