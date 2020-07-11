#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m=1000000007;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int last[257];
        for(int i=0;i<=256;i++)
        {
            last[i]=-1;
        }
        long long n=s.length();
         long long dp[n+1];
        
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(dp[i-1]*2)%m;
            
            if(last[s[i-1]]!=-1)
            {
                dp[i]=(dp[i]-dp[last[s[i-1]]] + m)%m;
            }
            
            last[s[i-1]]=i-1;
        }
        
        cout<<dp[n]%m<<endl;
        
    }
    return 0;
}
