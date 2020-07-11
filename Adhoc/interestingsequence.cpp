#include<bits/stdc++.h>
using namespace std;
int main() {

    int n,k,l;
        cin>>n>>k>>l;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
   int min=arr[0];
     for(int i=1;i<n;i++)
     {
         if(min>arr[i])
         {
            min=arr[i]; 
         }
     }
      
   int max=arr[0];
     for(int i=1;i<n;i++)
     {
         if(max<arr[i])
         {
            max=arr[i]; 
         }
     }
    int cost_min=INT_MAX;
    int cost=0;
    for(int ele=min;ele<=max;ele++)
    {
        int inc=0;
    int dec=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]<ele)
                inc+=ele-arr[j];
            else
                dec+=arr[j]-ele;
        }
        if(inc>=dec)
        {
            cost=dec*k+(inc-dec)*l;
                
     if(cost<cost_min)
    cost_min= cost;
        }
       
    
    }      
    
  cout<<cost_min<<"\n";
    return 0;
    
    
	// Write your code here
}
