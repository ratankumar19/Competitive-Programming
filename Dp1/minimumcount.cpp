using namespace std;
int minCount(int n){
   int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<n+1;i++)
    {
        dp[i]=n;
        for(int j=1;j*j<=i;j++)
        {
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
    return dp[n];
    
    
}
