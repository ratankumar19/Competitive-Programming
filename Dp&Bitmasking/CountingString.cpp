#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

int countStrings(char* x) {
    string s(x);
    ll n = s.length();
	ll dp[n];
	dp[n-1] = 0;
	for (ll i = n-2; i >= 0; i--) {
		dp[i] = (((dp[i+1]*26) % mod) + ('Z' - s[i+1])%mod)%mod;
	}
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += ((dp[i] + 1) * ('Z' - s[i])) % mod;
		sum %= mod;
	}
    return sum;
}
