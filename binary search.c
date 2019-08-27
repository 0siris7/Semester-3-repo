#include<iostream>
#include<conio.h>



int main()
{
          int a[10],i,key,mid;
          boolean found=false;
 
          for(i=0;i<10;i++)
         {
                 cout<<"ENTER A["<<i<<"] ELEMENT: ";
                 cin>>a[i];
         }
 
         cout<<"ENTER ELEMENT TO BE SEARCHED :";
         cin>>key;
 
         int first=0,last=9;
 
         while(first<=last)
        {
                mid= (first+last)/2;
  
               if(a[mid]==key)
              {
                        found=true;
                        break;
             }
             else if(a[mid]<key)
             {
                      first=mid+1;        //Restricting to subarray containing Larger values
             }
             else
             {
                     last= mid-1;        //Restricting to subarray containing Smaller values
             }
      }
 
       if(found)
      {
                cout<<"ELEMENT FOUND AT INDEX: "<<mid;
      }
      else
      {
              cout<<"ELEMENT NOT FOUND";
      }
 
      return 0;
}
