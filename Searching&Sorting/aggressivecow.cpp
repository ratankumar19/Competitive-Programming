#include<bits/stdc++.h>
typedef long long l;
using namespace std;
bool check(int cows,l arr[],int n,l dis)
{
    int count =1;
    l last_position=arr[0];
    for(int i=0;i<n;i++)
    {
        if((arr[i]-last_position) >= dis)
        {
            last_position=arr[i];
            count++;
        }
        if(count==cows)
        {
            return true;
        }
        
    }
    return false;
    
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        
        l arr[n];
        for(int i=0;i<n;i++)
        {cin>>arr[i];}
        sort(arr,arr+n);
        l ans=0;//=-1;
        l start=arr[0];
        l end=arr[n-1]-arr[0];
        
        while(start<=end)
        {
            l mid=start+(end-start)/2;
            if(check (c,arr,n,mid))
            {
                ans=mid;
                start=mid+1;
               
            }
            else
            { 
            end=mid-1;
            }
        }
        cout<<ans<<"\n";
        }
        return 0;
    }
    

	
