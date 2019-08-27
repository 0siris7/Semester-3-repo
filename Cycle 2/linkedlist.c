#include<conio.h>
#include<stdio.h>
struct ll
 {int data;
  struct ll *link;
       };
void traverse(struct ll *header)
 {
     struct ll *ptr;
     ptr=header->link;
     if(ptr==NULL)
      {printf("\nempty\n");
                  }
      else
      
     {while(ptr!=NULL)
      { printf(" %d ->",ptr->data);
        ptr=ptr->link;
       }
     } 
   
  }
  
  
struct ll *insertf(struct ll *header,int item)
 { struct ll *newnode;
   newnode=(struct ll*)malloc(sizeof(struct ll));
   newnode->data=item;
   newnode->link=header->link;
   header->link=newnode;
   return header;
       
 }

struct ll *deleter(struct ll *header)
 {
       if(header==NULL)
        {
        	printf("empty");
		}
	 else if(header->link==NULL)
	   {
	   	free(header);
	   	header=NULL;
	   }
	else
	{
		struct ll *temp=header->link;
		struct ll *temp2=header;
		while(temp->link!=NULL)
		 {
		 	temp2=temp;
		 	temp=temp->link;
		 }
		 free(temp);
		 temp2->link=NULL;
	}
	return header;
       
 }
 
 struct ll *deletea(struct ll *header,int key)
  { struct ll *ptr,*ptr1;
  int flag=0;
    ptr=header->link;
    if(ptr==NULL)
     {
                 printf("\nlist is empty");
                 
     }
     
     else
      { if(ptr->data==key)
         {
           header->link=ptr->link;
                          
           }
         else
          { while((ptr!=NULL)&&(flag==0))
             { if(ptr->data!=key)
               {  ptr1=ptr;
                  ptr=ptr->link;
                 }
                else
                 {flag=1;
                 }                         
                                         
             }
             if(ptr==NULL)
       { printf("\n no such element\n");
                   }
      else
       { ptr1->link=ptr->link;
                   
                   
                   
       }
           }
                 
      }
      
      
       return header;
       
    
  }
  
void destroy(struct ll *header)
   {
         
         struct ll *temp;
         temp=(struct ll*)malloc(sizeof(struct ll));
         while(header!=NULL)
         { temp=header;
           header=header->link;
           free(temp);
           }
           free(header);
                            
                            
                            
         
         
   }
  
int main()
{
     int ch=0,item;
     struct ll *header;
     header=(struct ll*)malloc(sizeof(struct ll));
     header->link=NULL;
     while(ch!=4)
      { printf("\n1.INSERTION AT FRONT\n2.DELETION AT REAR\n3.DELETE ANY ELEMENT\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
         {
                  case 1:
                          printf("enter the element:");
                          scanf("%d",&item);
                          header=insertf(header,item);
                          traverse(header);
                          break;
                  
                  case 2:
                          header=deleter(header);
                          traverse(header);
                          break;
                  
                  
                case 3:
                         printf("\nenter element to be removed:");
                         scanf("%d",&item);
                         header=deletea(header,item);
                         traverse(header);
                         break;  
         }
         
     }
     
     
     
     
     getch();
     return 0;
    }  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
