#include<bits/stdc++.h>
using namespace std;
int helper(int arr[],int i,int n,int* dp){
    if(i>=n)
        return 0;
    if(dp[i]>0)
        return dp[i];
    dp[i] = max(arr[i]+helper(arr,i+2,n,dp),helper(arr,i+1,n,dp));
    return dp[i];
}
int getMaxMoney(int arr[], int n){
    int *dp = new int[n+2];
    for(int i=0;i<n+2;i++)
        dp[i]=0;
return helper(arr,0,n,dp);
}

