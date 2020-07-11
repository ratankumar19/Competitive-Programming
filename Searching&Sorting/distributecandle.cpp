#include<bits/stdc++.h>
typedef long long l;
using namespace std;
bool check(l s,l arr[],l n,l dis)
{
  //  l last_position=arr[0];
    l sum=0;
    for(l i=0;i<n;i++)
    {
         sum=sum+arr[i]/dis;
        
         if(sum>=s)
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
        l n,c;
        cin>>n>>c;
        
        l arr[n];
        for(l i=0;i<n;i++)
        {cin>>arr[i];}
        sort(arr,arr+n);
        l ans=-1;
        l start=0;
        l end=arr[n-1];
        
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
    

	// Write your code here

