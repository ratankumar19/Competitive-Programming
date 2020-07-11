#include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    #define db double
    #define F first
    #define S second
    const ll mod=1e9+7;
    ll dp[1000010];
    ll power(ll n,ll m){
        ll res=1;
        while(m>0){
            if(m%2==1)  res=(res*n)%mod;
            n=(n*n)%mod;
            m/=2;
        }
        return res;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        ll n,k,x,y,T;
        cin>>T;
        dp[0]=1;
        for(int i=1;i<1000010;i++){
            dp[i]=(i*dp[i-1])%mod;
        }
        while(T--){
          cin>>n>>k;
          ll ans=1;
          if(n!=k)
          ans=(((dp[n]*power(dp[k],mod-2))%mod)*power(dp[n-k],mod-2))%mod;
          ans=(ans*power(2,k))%mod;
          cout<<ans<<"\n";
        
        
        }
         
    }
