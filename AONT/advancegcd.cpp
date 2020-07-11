
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll helper(string s, ll a)
{
	ll smallint = 0;
	for (int i = 0; i < s.length(); i++)
	{
		 smallint = ( smallint* 10 + int(s[i] - '0'))%a;
	}
	return  smallint;
}
ll gcd(ll a, ll b)
{
	if (a == 0) return b;
	return gcd(b, b%a);
}
int main()
{
    int t;
    cin>>t;
	while (t--)
	{
        ll a;
        string b;
		cin >> a >> b;
      if(a==0) cout<<b<<endl;
		else
		{
		ll smallans= helper(b,a);
		ll ans = gcd(a,smallans);
		cout << ans << endl;
        }
	}
		return 0;
}
