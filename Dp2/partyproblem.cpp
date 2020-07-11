#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        int sum,n,i,j;
        cin>>sum>>n;
        if(sum==0&&n==0)
            break;
        int mon[n],hapi[n];
        for(i=0;i<n;i++)
            cin>>mon[i]>>hapi[i];
        int** dp=new int*[n+1];
        for(i=0;i<=n;i++)
            dp[i]=new int[sum+1];
        for(i=0;i<=sum;i++)
            dp[0][i]=0;
        for(i=0;i<=n;i++)
            dp[i][0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                dp[i][j]=dp[i-1][j];
                
                if(mon[i-1]<=j)
                {
                    dp[i][j]=max(dp[i][j],hapi[i-1]+dp[i-1][j-mon[i-1]]);
                }
                
            }
        }
        int ans=dp[n][sum];
        int mini=0;
        for(i=0;i<=sum;i++)
        {
            if(ans==dp[n][i])
            {
                mini=i;
                break;
            }
        }
        for(i=0;i<=n;i++)
            delete [] dp[i];
        delete [] dp;
        cout<<mini<<" "<<ans<<endl;
    }
    return 0;
}
