#include<bits/stdc++.h>
#define ull long long 
#define ll long long 
#define PII pair<int,int>
#define mk make_pair
#define pb push_back
#define mod 1000000007
using namespace std;
 
void multiply(ull A[2][2],ull M[2][2]){
  ll m=mod-1;
ull fval=(A[0][0]*M[0][0] + A[0][1]*M[1][0])%m;
ull sval=(A[0][0]*M[0][1] + A[0][1]*M[1][1])%m;
ull tval=(A[1][0]*M[0][0] + A[1][1]*M[1][0])%m;
ull foval=(A[1][0]*M[0][1] + A[1][1]*M[1][1])%m;
A[0][0]=fval;
A[0][1]=sval;
A[1][0]=tval;
A[1][1]=foval;
 
}
ull fibo(ull n){
ull M[2][2]={{1,1},{1,0}};
ull W[2][2]={{1,0},{0,1}};
 
if(n==0)
  return 0;
 // n--;
  while(n){
    if(n%2!=0){
      multiply(W,M);
    }
    multiply(M,M);
    n>>=1;
  }
  return W[1][0];
 
}
ll mp(ll a,ll b){
  ll ans=1;
  while(b){
    if(b&1){
      ans=(ans*a)%mod;
  }
      a=(a*a)%mod;
      b>>=1;
  }
  return ans;
}
int main(){
	int t;
  cin>>t;
  while(t--){
    ll a,b,n;
    cin>>a>>b>>n;
    if(n==0){
      cout<<a<<endl;
      continue;
    }
    if(n==1){
      cout<<b<<endl;
      continue;
    }
    if(a==0 && b==0){
      cout<<a<<endl;
      continue;
    }
   ll xa=fibo(n-1);
   ll xb=fibo(n);
   ll ans= mp(a+1,xa)*mp(b+1,xb);
    ans--;
    ans=ans%mod;
    if(ans<0){
      ans+=mod;
    }
    cout<<ans<<endl;
    
    
    
  }
  
 
 
return 0;
}
