#include <stdio.h>
#include <string.h>
#define M 750000
#define MOD 1000000007
 
int inp[M+1], dp[M+1];
 
int main() {
  int t,n,sum;
  scanf("%d", &t);
  while(t--) {
    sum = 0;
    memset(inp, 0, sizeof(inp));
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0, j; i < n; ++i) {
      scanf("%d", &j);
      inp[j] = 1;
    }
    for(int i = 1; i <= M; ++i) {
      if(inp[i]) {
        dp[i] = (dp[i] + 1) % MOD;
        sum = (sum + 1) % MOD;
        for(int j = 2 * i; j <= M; j += i) {
          if(inp[j]) {
            dp[j] = (dp[j] + dp[i]) % MOD;
            sum = (sum + dp[i]) % MOD;
          }
        }
      }
    }
    printf("%d\n", sum);
  }
 return 0;
}
