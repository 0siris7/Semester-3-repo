#include<stdio.h>
#include<conio.h>
#include<math.h>

void push(float value,int *top,int size,float exp[])
 {
     if(*top>=size)
       {
                   printf("\nSTACK IS FULL\n");
                   
       }
     
     else
      { (*top)++;
         exp[*top]=value;
                   
                   
                   
      }
     
 }
 
 
 float pop(int *top,int size,float exp[])
  { float value;
       if(*top<0)
        { printf("\nSTACK IS EMPTY\n");
                 
                 }
       else
        { value=exp[*top];
        (*top)--;
                 
        }
       return value;
       
  }
       
       
 void main()
  { char s[100];
    int i,top=-1,size=0,power=0;
    float value,x,y;
    
    printf("enter the string:");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
     {
        size++;                   
     }
     
    float exp[size];
    
    for(i=0;s[i]!='\0';i++)
     {
       if(s[i]>='a' && s[i]<='z'||s[i]>='A'&&s[i]<='Z')
         {
           printf("\nenter value of %c",s[i]);
           scanf("%f",&value);
           push(value,&top,size,exp);
         }
         
       else
         { 
           y=pop(&top,size,exp);
           x=pop(&top,size,exp);
           
           printf("\nEXPRESSION: %f %c %f",x,s[i],y);
           
           switch(s[i])
            { 
              case '+':
                        push(x+y,&top,size,exp);
                        break; 
              case '-':
                        push(x-y,&top,size,exp);
                        break;          
                       
              case '*':
                        push(x*y,&top,size,exp);
                        break;         
                       
              case '/':
                        push(x/y,&top,size,exp);
                        break;         
                       
              case '^':
                        power=pow(x,y);
                        push(power,&top,size,exp);
                        break;         
                       
          }
                                     
       }                        
                           
    }
    
    
    float result=pop(&top,size,exp);
    printf("\nEVALUATED EXPRESSION:%f",result);
    getch();
      
 }     
       
       
       
       
       
       
       
       
       
       
       
       
       
       
