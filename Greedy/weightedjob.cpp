#include<bits/stdc++.h>
using namespace std;
struct job{
    int start,finish,profit;
    
};
bool compare(struct job a,struct job b){
    return a.finish<b.finish;
    
}
int binary(struct job arr[],int i){
  int l=0;int h=i-1;
    while(l<=h){
        int mid=(l+h)/2;//
        //jb value exist kree 
        if(arr[mid].finish==arr[i].start){
            return mid;
        }else if(arr[mid].finish<=arr[i].start){
                l=mid+1;
            }  
    else h=mid-1;
    
}return -1;
}
int helper(struct job arr[],int n){
    sort(arr,arr+n,compare);
    int *dp=new int[n];
    dp[0]=arr[0].profit;
    
    
    for(int i=1;i<n;i++){
       int inc=arr[i].profit;
       int j=binary(arr,i);
    	inc+=dp[j];   
        dp[i]=max(inc,dp[i-1]);
    }
    int ans=dp[n-1];
    return ans;
}
int main()
{
    
    int n;cin>>n;
    struct job j[n];
    for(int i=0;i<n;i++){
        cin>>j[i].start>>j[i].finish>>j[i].profit;
    }
    cout<<helper(j,n)<<"\n";
    return 0;
}
