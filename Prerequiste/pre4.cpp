#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        
    }
    int i;
    int j;
    
    for(i=0 , j=(n-1)-i;i<=n/2 , j>=n/2;i++, j--)
    {
        int sum=0;
        sum+=arr[i]+arr[j];
        int p=(sum / 10);
        int q=(sum % 10);
        cout<<p<<" "<<q<<endl;
        
        
    }
    
	return 0;
}

