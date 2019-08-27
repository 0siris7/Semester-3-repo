#include<conio.h>
#include<stdio.h>
struct ll
{
       int d;
       struct ll *lc,*rc;
};
struct ll *r,*f;

int e(struct ll *ptr)
{   
    int item;
    char c='n',ch='n';
    struct ll *lcptr,*rcptr;
    if(ptr!=NULL)
    {
               
             printf("Enter the value of node:");
             scanf("%d",&item);
             ptr->d=item;
             printf("do you want to have a left sub tree for %d   (y/n) :",item);
             fflush(stdin);
             scanf("%c",&c);
             if(c=='y')
             {
                 lcptr=(struct ll*)malloc(sizeof(struct ll)); 
                 lcptr->lc=lcptr->rc=NULL;
                 ptr->lc=lcptr;
                 e(lcptr);
              }
              else
              {  
                  lcptr=(struct ll*)malloc(sizeof(struct ll)); 
                  lcptr=NULL;
                  ptr->lc=NULL;
                  e(lcptr);
              }
              printf("Do you want to crate a right sub tree for %d  (y/n)  :",item);
              fflush(stdin);
              scanf( "%c",&ch);
              if(ch=='y')
              {
                   rcptr=(struct ll*)malloc(sizeof(struct ll)); 
                   rcptr->lc=rcptr->rc=NULL;
                   ptr->rc=rcptr;
                   e(rcptr);
                         
              }
              else
              {                                            
                  rcptr=(struct ll*)malloc(sizeof(struct ll)); 
                  rcptr=NULL;
                  ptr->rc=NULL;
                  e(rcptr);
              }
}
}    
int itraversal(struct ll *ptr)
{
    if(ptr!=NULL)
    {
                 itraversal(ptr->lc);
                 printf("%d",ptr->d);
                 itraversal(ptr->rc);
    }
}
int posttraversal(struct ll *ptr)
{
    if(ptr!=NULL)
    {
                 posttraversal(ptr->lc);
                 posttraversal(ptr->rc);
                 printf("%d",ptr->d);
    }
}
int pretraversal(struct ll *ptr)
{
   if(ptr!=NULL)
    {
                 printf("%d",ptr->d);
                 pretraversal(ptr->lc);
                 pretraversal(ptr->rc);
                 
     }
} 
void search(struct ll *ptr,int item)
{
    if(ptr!=NULL)
    {
        if(ptr->d==item)
        f=ptr;
        search(ptr->lc,item);
        search(ptr->rc,item);
     }
}
void parent(struct ll *ptr,int item)
{
     if(ptr!=NULL)
     {
    if(ptr->lc!=NULL)
    { 
                          if(ptr->lc->d==item)
                      
                          f=ptr;
                          parent(ptr->lc,item);
        
    }
    if(ptr->rc!=NULL)
    {
                         if(ptr->rc->d==item)
                         f=ptr;
                         parent(ptr->rc,item);
     }
     }
}
void deletebt()
{
    int item;
    struct ll *r1,*r2;
    r1=(struct ll*)malloc(sizeof(struct ll));
    r2=(struct ll*)malloc(sizeof(struct ll));
    f=NULL;
    printf("Enter the item to be deleted   :");
    fflush(stdin);
    scanf("%d",&item);
    if(r==NULL)
    {
      printf("\nDeletion not possible  ");          
      return;
      }
    if(r->d==item)
    {             if((r->lc==NULL)&&(r->rc==NULL))
                      r=NULL;
                  else
                      printf("\nDeletion not possible  ");    
    }
    else
    {
    search(r,item);
    if((f->lc==NULL)&&(f->rc==NULL))
    {
    f=NULL;
    
    parent(r,item);
    
    if(f!=NULL)
    {        
              if(f->rc!=NULL)
               r1=f->rc;
               
                if(f->lc!=NULL)
               r2=f->lc;
               
               if(r1->d==item)
               {
                              
                              f->rc=NULL;
                               
               }
               
               else if(r2->d==item)
               {
                    
                    f->lc=NULL;   
                     printf("7"); 
               }
    }                                 
    else
    printf("no such element exists ");
}
else 
printf("deletion not possible");
}
}
void insertbt(struct ll *ptr)
{       int t,item;
        char c,ch;
        struct ll *lcptr;
        
        f=NULL;
        printf("Enter the root to which item is to be added  :");
        fflush(stdin);
        scanf("%d",&item);
        search(r,item);
        if(f!=NULL)
        {
        if(f->lc==NULL)
        {
        printf("do you want to have a left sub tree for %d   (y/n) :",f->d);
        fflush(stdin);
        scanf("%c",&c);
        if(c=='y')
        {        
                 printf("Enter the value ");
                 scanf("%d",&t);
                 lcptr=(struct ll*)malloc(sizeof(struct ll)); 
                 lcptr->lc=lcptr->rc=NULL;
                 lcptr->d=t;
                 f->lc=lcptr;
                 
              }  
              }
              else
               printf("no leaf available");                                   
        
        if(f->rc==NULL)
        {
        printf("do you want to have a right sub tree for %d   (y/n) :",item);
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y')
        {        
                 printf("Enter the value ");
                 scanf("%d",&t);
                 lcptr=(struct ll*)malloc(sizeof(struct ll)); 
                 lcptr->lc=lcptr->rc=NULL;
                 lcptr->d=t;
                 f->rc=lcptr;
                 
         }     } 
         else
         printf("no leaf available");
         }
         else
         printf("no such root");
}                                   
int main()
{
    int q;
    char c='y';
    r=(struct ll*)malloc(sizeof(struct ll));
    f=(struct ll*)malloc(sizeof(struct ll));
    r->lc=r->rc=NULL;
    e(r);
    printf("\n Inorder traversal   :");
    itraversal(r);
    printf("\nPostorder traversal  :");
    posttraversal(r);
    printf("\nPreorder traversal   :");
    pretraversal(r);
    while(c=='y')
    {
                 printf("\n1-inset   \n2-delete  ");
                 fflush(stdin);
                 scanf("%d",&q);
                 switch(q)
                 {
                          case 1:
                               {  printf("\n");
                                  insertbt(r);
                                  printf("\n Inorder traversal   :");
                                 itraversal(r);
                                 printf("\nPostorder traversal  :");
                                 posttraversal(r);
                                 printf("\nPreorder traversal   :");
                                 pretraversal(r);
                                 break;
                                 }
                           case 2:
                                {
                                       printf("\n");
                                      deletebt(r);
                                 printf("\n Inorder traversal   :");
                                 itraversal(r);
                                 printf("\nPostorder traversal  :");
                                 posttraversal(r);
                                 printf("\nPreorder traversal   :");
                                 pretraversal(r);
                                 break;
                                 }
                                 }
                  printf("\ndo you want to continue (y/n):");
                  scanf("%d",&c);
                  }
    
getch();
}

               

