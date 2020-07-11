
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum1=0,sum2=0;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    for(int i=0;i<n;i+=2)
    {
        if(arr[i]%2==0)
        {
            sum1+=arr[i];
        }
    }
    for(int j=1;j<n;j+=2)
    {
        if(arr[j]%2==1)
        {
            sum2+=arr[j];
        }
    }
    cout<<sum1<<" "<<sum2<<endl;
        
	return 0;
}

