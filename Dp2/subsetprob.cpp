#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
      cin>>a[i];
    int sum;
    cin>>sum;
    bool** dp=new bool*[n+1];
    for(i=0;i<=n;i++)
        dp[i]=new bool[sum+1];
    for(i=0;i<=sum;i++)
        dp[0][i]=false;
    for(i=0;i<=n;i++)
        dp[i][0]=true;
    int sum1=0;
    for(i=1;i<=n;i++)
    {
        
        for(j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if((j-a[i-1])>=0)
                dp[i][j]=dp[i][j]||dp[i-1][j-a[i-1]];
        }
    }
    bool ans=dp[n][sum];
    for(i=0;i<=n;i++)
        delete [] dp[i];
    delete [] dp;
    if(ans==true)
    cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
