#include<stdio.h>
#include<conio.h>

struct node
{
       int data;
       struct node *lc,*rc;
};
struct node *root;
struct node *build_tree(struct node *ptr)
{   
    int item;
    char c,ch;
    struct node *lcptr,*rcptr;
    if(ptr!=NULL)
    {
               
             printf("\nEnter value of node:");
             scanf("%d",&item);
             ptr->data=item;
             printf("\nCreate left sub tree(y/n)?:");
             fflush(stdin);
             scanf("%c",&c);
             if(c=='y')
             {
                 lcptr=(struct node*)malloc(sizeof(struct node)); 
                 lcptr->lc=NULL;
                 lcptr->rc=NULL;
                 ptr->lc=lcptr;
                 build_tree(lcptr);
              }
              else
              {  
                  lcptr=(struct node*)malloc(sizeof(struct node)); 
                  lcptr=NULL;
                  ptr->lc=NULL;
                  build_tree(lcptr);
              }
              printf("\ncreate  right sub tree(y/n)?:");
              fflush(stdin);
              scanf( "%c",&ch);
              if(ch=='y')
              {
                   rcptr=(struct node*)malloc(sizeof(struct node)); 
                   rcptr->lc=NULL;
                   rcptr->rc=NULL;
                   ptr->rc=rcptr;
                   build_tree(rcptr);
                         
              }
              else
              {  
                  rcptr=(struct node*)malloc(sizeof(struct node)); 
                  rcptr=NULL;
                  ptr->rc=NULL;
                  build_tree(rcptr);
              }
}
return ptr;
} 


 void traverse_in(struct node *ptr)
{
    if(ptr!=NULL)
    {            
                 
                 traverse_in(ptr->lc);
                 printf(" %d ",ptr->data);
                 traverse_in(ptr->rc);
    }
}
void traverse_post(struct node *ptr)
{
    if(ptr!=NULL)
    {
                 traverse_post(ptr->lc);
                
                 traverse_post(ptr->rc);
                  printf(" %d ",ptr->data);
    } 
}

void traverse_pre(struct node *ptr)
{
    if(ptr!=NULL)
    {
                 printf(" %d ",ptr->data);
                 traverse_pre(ptr->lc);
                
                 traverse_pre(ptr->rc);
                  
    } 
}
struct node *parent(struct node *ptr,struct node *f,int item)
{   
    
    if(ptr!=NULL)
    {
        if((ptr->lc->data==item)||(ptr->lc->data==item))
        f=ptr;
        search(ptr->lc,item);
        search(ptr->rc,item);
     }
     return f;
}

struct node *deletebt(struct node *ptr)
{
    int item;
    struct node *f;
    
    f=NULL;
    printf("Enter the item to be deleted:");
    scanf("%d",&item);
    f=parent(ptr,f,item);
    if(f!=NULL)
    {
               if((f->rc->data==item)
               {
                                  f->rc=NULL;
               }
               else if(f->lc->data==item)
               {
                    
                    f->lc=NULL;    
               }
    }                                 
    else
    {printf("no such element exists ");
     }
    return ptr;
}
 
 int main()
 {
    root=(struct node*)malloc(sizeof(struct node));
    root->lc=NULL;
 
    root->rc=NULL;
    printf("Build tree:");
    root=build_tree(root); 
    printf("Inorder traversal:");
    traverse_in(root);
    printf("\npost order traversal:");
    traverse_post(root);
    printf("\npreorder traversal:");
    traverse_pre(root);
    root=deletebt(root);
    printf("Inorder traversal:");
    traverse_in(root);
    printf("\npost order traversal:");
    traverse_post(root);
    printf("\npreorder traversal:");
    traverse_pre(root);
    getch(); 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 /*int search(struct ll *ptr,item)
{   struct node *f;
    if(ptr!=NULL)
    {
        if((ptr->data==item)
        f=ptr;
        search(ptr->lc,item);
        search(ptr->rc,item);
     }
}
*/
 
 
 
 
 
 
 
 
 
 
 
 
 
 
