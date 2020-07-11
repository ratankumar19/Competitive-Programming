#include<bits/stdc++.h>
using namespace std;
typedef int  lli;
lli arr[600000];
vector<pair<lli,lli> > v;
lli seg[600000][52];
lli dp[600000][52];
lli dp2[600000][52];
#define mod 5000000

void update(int idx,int start,int end,int ups,int upe,int didx,lli val)
 {
  if(start>end || upe<start || ups>end) return ;
  else if(start==end && start==ups)
    {
      seg[idx][didx]=val;
      return ;
   }
   int mid=(start+end)/2;
   update(2*idx,start,mid,ups,ups,didx,val);
   update(2*idx+1,mid+1,end,ups,upe,didx,val);
   seg[idx][didx]=(seg[2*idx][didx]+seg[2*idx+1][didx])%mod;
 }

 lli  qry(int idx,int start,int end,int qs,int qe,int didx)
 {
  if(start>end || qe<start || qs>end) return 0 ;
  else if(start>=qs && end<=qe)
    {
      return seg[idx][didx];
   }
   int mid=(start+end)/2;
  lli q1= qry(2*idx,start,mid,qs,qe,didx);
  lli q2= qry(2*idx+1,mid+1,end,qs,qe,didx);
    return (q1+q2)%mod;
 }


int main()
 {
  int n,k;
   cin>>n>>k;
   for(int i=0;i<n;i++)
     {
     int a; cin>>a;
     v.push_back({a,i});
   }
   sort(v.begin(),v.end());
    
   for(int i=0;i<n;i++)
    {
           int num=v[i].first;
            int idx=v[i].second;
            update(1,0,n-1,idx,idx,1,1);
            dp[i][1]=1;
             for(int j=2;j<=k;j++)
                {
              lli count=qry(1,0,n-1,0,idx-1,j-1);
              dp[i][j]=(count-dp2[num][j-1]+mod)%mod;
               update(1,0,n-1,idx,idx,j,dp[i][j]);
          
          }
    for(int j=1;j<=k;j++)
     {
      dp2[num][j]=(dp2[num][j]+dp[i][j])%mod;
     }
    
    }
    
     lli ans=0;
     for(int i=0;i<n;i++)
       {
        ans=(ans+dp[i][k])%mod;
   }
    cout<<ans<<endl;
 }
