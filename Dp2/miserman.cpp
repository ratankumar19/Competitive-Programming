#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f=0;
ll helper(ll** ar,ll row,ll col,ll currow,ll curcol,ll** dp){
//     if(currow>=row || curcol<0 || curcol>=n){
        
//     }
    if(currow==row-1){
        return ar[currow][curcol];
    }
    if(dp[currow][curcol]!=-1){
        return dp[currow][curcol];
    }
    
    ll p= ar[currow][curcol];
    ll m,n=INT_MAX,b=INT_MAX;
     m = helper(ar,row,col,currow+1,curcol,dp);
    
    if(curcol+1<col)
     n = helper(ar,row,col,currow+1,curcol+1,dp);
    if(curcol-1>=0)
     b = helper(ar,row,col,currow+1,curcol-1,dp);
   // cout<<p<<" "<<b<<" "<<m<<" "<<n<<endl;
    ll total= min(m,min(n,b));
    dp[currow][curcol]=p+total;
    return p+total;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll** ar=new ll*[n];
    ll i;
    for(i=0;i<n;++i){
        ar[i]=new ll[m];
    }
    for(i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            cin>>ar[i][j];
        }
    }
    
     ll** dp=new ll*[n+1];
   // ll i;
    for(i=0;i<n+1;++i){
        dp[i]=new ll[m+1];
    }
    for(i=0;i<n+1;++i){
        for(ll j=0;j<m+1;++j){
            dp[i][j]=-1;
        }
    }
    
    ll o,min=INT_MAX;
    for(i=0;i<m;++i){
        o=helper(ar,n,m,0,i,dp);
        if(min>o){
            min=o;
        }
    }
    cout<<min<<endl;
    
    return 0;
}
