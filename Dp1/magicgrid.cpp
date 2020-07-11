#include <bits/stdc++.h>
using namespace std;
int grid(int **input,int m,int n)
{
    int dp[m][n];
    dp[m-1][n-1]=1;
    //dp[m][n-1]=1;
   
   
    for(int j=n-2;j>=0;j--)
    {
        dp[m-1][j]=dp[m-1][j+1]-input[m-1][j];
        if(dp[m-1][j]<=0)
            dp[m-1][j]=1;
            
    }
    for(int i=m-2;i>=0;i--)
    {
        dp[i][n-1]=dp[i+1][n-1]-input[i][n-1];
        if(dp[i][n-1]<=0)
            dp[i][n-1]=1;
    }
    for(int i=m-2;i>=0;i--)
    {
         for(int j=n-2;j>=0;j--)
         {
             dp[i][j]=-input[i][j]+min(dp[i+1][j],dp[i][j+1]);
            if(dp[i][j]<=0)
                dp[i][j]=1; 
         }
        
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
            
        }
        cout<<"\n";
    }
    return dp[0][0];
    
}




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
    int **arr = new int* [m];
for(int i=0;i<m;i++){
    arr[i]=new int[n];  
for(int j=0;j<n;j++){
       cin>> arr[i][j];
}}   
       cout<<"value is"<<grid(arr,m,n)<<"\n";
    }
 return 0;
}
