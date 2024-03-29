//Implementtaion of Tree using array


#include<stdio.h>
void create (int bin[],int i)
{
     char ch;
     
     printf("\nEnter data:");
     scanf("%d",&bin[i]);
     printf("\nDo you want to create a left child for %d (y/n):",bin[i]);
     scanf(" %c",&ch);
     if(ch=='y')
     {
            create(bin,i*2);
     }
     else
     
            bin[i*2]=0;
            
     printf("\nDo you want to create a right child for %d (y/n):",bin[i]);
     scanf(" %c",&ch);
     if(ch=='y')
     {
            create(bin,i*2+1);
     }
     else
            bin[i*2+1]=0;
            
       
}  
int search(int bin[],int item,int i,int check)
{    
       if(bin[i]==item)
       {
            check=i;           
            return check;
            }
       if(check!=0)
       {
            return check;
       }
       if(bin[i]==0)
       {
            return 0;
       }
       check=search(bin,item,i*2,check);
       check=search(bin,item,i*2+1,check);                                 
       return check;                  
       
}
int searchpar(int bin[],int item,int i,int check)
{
    if(bin[i*2]==item)
    {
           check=i;
           return i;
    }
    if(bin[i*2+1]==item)
    {
           check=i;
           return i;
    }
    if(check!=0)
           return check;
    if(bin[i]==0)
         return 0;
    check=searchpar(bin,item,i*2,check);
    check=searchpar(bin,item,i*2+1,check);                                 
    return check;  
}
void insert(int bin[],int parent,int item)
{
     char ch;
     int i;
     i=search(bin,parent,1,0);
     if(i==0)
         printf("\nInsertion not possible");
     else
         {
              printf("Left or Right ?(l/r):");
              scanf(" %c",&ch);
           if(ch=='l')
           {
                   if(bin[i*2]==0)
                   {
                          bin[i*2]=item;
                          
                   }
                  else
                  {
                        printf("\nInsertion not possible at left child");
                  }
          }
           if(ch=='r')
           {
                   if(bin[i*2+1]==0)
                   {
                          bin[i*2+1]=item;
                          
                  }
                  else
                  {
                        printf("\nInsertion not possible at right child");
                  }
          }
                                                
     }                    
     
}
void del(int bin[],int item)
{
     int i;
     i=searchpar(bin,item,1,0);
     if(i!=0)
     {
            if(bin[i*2]==item)
            {
                  if(bin[(i*2)*2]==0&&bin[(i*2)*2+1]==0)
                  {
                            bin[i*2]=0;
                  }
                  else
                           printf("\nNot a leaf node");
            }
            if(bin[i*2+1]==item)
            {
                  if(bin[(i*2+1)*2]==0&&bin[(i*2+1)*2+1]==0)
                  {
                            bin[i*2+1]=0;
                  }
                  else
                           printf("\nNot a leaf node");
            }                                                                                            
                                                                                
     }
     else
             printf("\nDeletion not possible");
                   
}                              
                                                                   
                                                                 
void traverse(int bin[],int i)
{
     if(bin[i]==0)
        return;
     traverse(bin,i*2);
     printf(" %d ",bin[i]);
     traverse(bin,i*2+1);
}
int main()
{
    int bin[100],i=0,ch=1,parent,item;
    while(i<100)
    {
         bin[i]=0;
         i++;
    }
    create(bin,1);
    traverse(bin,1);
    
    while(ch!=4)
     {
             printf("\n1:Insertion\n2:Deletion\n3:Traversal\n4:Exit\n");
             scanf("%d",&ch);    
            switch(ch)
             {
                       case 1:
                            printf("\nEnter parent:");
                            scanf("%d",&parent);
                            printf("\nEnter item:");
                            scanf("%d",&item);
                            insert(bin,parent,item);
                            printf("\n");
                            traverse(bin,1);
                            break;
                      case 2:
                           printf("\nEnter the node to be deleted:");
                           scanf("%d",&item);
                           del(bin,item);
                           printf("\n");
                           traverse(bin,1);
                           break;
                     case 3:
                           traverse(bin,1);
                                        
             }
     }                     
    
    getch();
}   


/***********************************************************************************
OUTPUT:

 Enter Data  :1
Do You Want To Create a Left-Child (1/0) : 1

 Enter Data  :2
Do You Want To Create a Left-Child (1/0) : 0
Do You Want To Create a Right-Child (1/0) : 0
Do You Want To Create a Right-Child (1/0) : 1

 Enter Data  :3
Do You Want To Create a Left-Child (1/0) : 0
Do You Want To Create a Right-Child (1/0) : 0

 Traversal  :
 Pre Order Traversal  : 1       2       3
 InOrder Traversal   : 2        1       3
 Post Order Traversal : 2       3       1

Enter the Operation to be performed
 1 Insertion
 2 Deletion
 3 Traversal
 4 exit
1

Enter Parent :4

Enter Item :5

Insertion not Possible
 Traversal  :
 Pre_Order Traversal  : 1       2       3
 In_Order Traversal   : 2       1       3
 Post_Order Traversal : 2       3       1

Enter the Operation to be performed
 1 Insertion
 2 Deletion
 3 Traversal
 4 exit
3

 Traversal  :
 Pre Order Traversal  : 1       2       3
 InOrder Traversal   : 2        1       3
 Post Order Traversal : 2       3       1

Enter the Operation to be performed
 1 Insertion
 2 Deletion
 3 Traversal
 4 exit
1

Enter Parent :3

Enter Item :4
left=1 /right =0  (1/0) ;0

 Insertion Not Possible As Right child
 Traversal  :
 Pre_Order Traversal  : 1       2       3
 In_Order Traversal   : 2       1       3
 Post_Order Traversal : 2       3       1

Enter the Operation to be performed
 1 Insertion
 2 Deletion
 3 Traversal
 4 exit*/
