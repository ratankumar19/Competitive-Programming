#include<bits/stdc++.h>
#define ll int

#define mod 1000000007
#define siz 5001

using namespace std;
ll dp[10001][5002];
ll findans(ll *cap,ll *asis,ll n,ll pos,ll crew)
{
	if(pos == n)
		return 0;
		
	if(dp[pos][crew]!=-1)	
        return dp[pos][crew];
	if(n-pos == crew)
		return dp[pos][crew] = cap[pos] + findans(cap,asis,n,pos+1,crew-1);
		
	if(crew == 0)
		return dp[pos][crew] = asis[pos] + findans(cap,asis,n,pos+1,crew+1);
	
	ll capt = cap[pos] + findans(cap,asis,n,pos+1,crew-1);
	ll asist = asis[pos] + findans(cap,asis,n,pos+1,crew+1);
	return dp[pos][crew] = min(capt,asist);			
}
int main()
{
	ll n,m,i,j;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	ll cap[n],asis[n];
	for(i = 0;i<n;i++)
	cin>>cap[i]>>asis[i];
	
	cout<<findans(cap,asis,n,0,0);
	
	
}
