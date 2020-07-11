#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,X,Y;
    cin>>n>>X>>Y;
    string a;
    cin>>a;
    long int c=0;
  
  
     for(int i=0;i<n;i++)
    {
          if(a[i]=='1' && a[i+1]=='0')
          {
          
             c++;
         

          } }    
    
       if(a[0]=='0')
       {
           c=c+1;
           
   
        
       }
 
    if(c!=0)
    {
        
 long int cost=(c-1)*min(x,y)+y;
        cout<<cost<<"\n";
       }
    else
    {
        cout<<"0"<<"\n";
    }
	return 0;
}
