 #include<bits/stdc++.h>
using namespace std;
int main() {
int n,count=0;

    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        
    }
   int min,max,z;
    int temp=0;
    
    for(int i=0;i<n-1;i++)
    {
         min=arr[i];
          max=arr[i+1];
        
        for(int j=i+2;j<n;j++)
        {
        if(arr[j]>max)
        {
            max=arr[j];
        }
    }
   
       

  
        z=max- min;

    
        if(temp < z)
        temp=z;
  
    } 
       
    cout<<temp<<"\n";
	
}

