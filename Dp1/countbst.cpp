#define ll long long
#define M 1000000007
ll int countBST( int n)
{	
    ll int* dp=new ll int[n+1];
    if(n==0)
    return 1;
    if(n==1)
	return 1;
    if(n==2)
    return 2;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {	dp[i]=0;
        for(int j=1;j<=i;j++)
        {
            dp[i]+=dp[j-1]*dp[i-j];
            dp[i]%=M;
        }
    }
    int ans=dp[n];
    delete [] dp;
    return ans;
}



