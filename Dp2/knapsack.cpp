/// memorisation with recursion 
#include <bits/stdc++.h> 
using namespace std;
int knapsackHelper(int* wt,int* val,int n,int w,int **dp){
    
    if(n==0||w==0)
    return 0;
    
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    
  
    if(w>=wt[n-1])
        return max(val[n-1]+knapsackHelper(wt,val,n-1,w-wt[n-1],dp),knapsackHelper(wt,val,n-1,w,dp));

   
    else
        return knapsackHelper(wt,val,n-1,w,dp);
        
  
    dp[n][w]=max(val[n-1]+knapsackHelper(wt,val,n-1,w-wt[n-1],dp),knapsackHelper(wt,val,n-1,w,dp));

    return max(val[n-1]+knapsackHelper(wt,val,n-1,w-wt[n-1],dp),knapsackHelper(wt,val,n-1,w,dp));

    
}



int knapsack(int* wt,int* val,int n,int w){
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i]=new int[w+1];
        for(int j=0;j<w+1;j++){
            dp[i][j]=-1;
        }
    }
    
    int ans=knapsackHelper(wt,val,n,w,dp);
    
    for(int i=0;i<n+1;i++){
        delete [] dp[i];
    }
    delete []dp;
    return ans;
    
}
