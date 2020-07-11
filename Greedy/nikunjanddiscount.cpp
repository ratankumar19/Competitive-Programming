#include<bits/stdc++.h>
using namespace std;
long helper(int *arr,int n){
    
    sort(arr,arr+n);
    long sum=0;
    for(long i=0;i<n;i++){
        sum=sum+pow(2,n-(i+1))*arr[i];
    }
    return sum;
}
int main()
{
    int n;cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    long ans=helper(arr,n);
    cout<<ans;
        
    //Write your code here
    return 0;
}
