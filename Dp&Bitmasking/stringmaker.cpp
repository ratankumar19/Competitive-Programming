#include<bits/stdc++.h>
#define MOD 1000000007

int solveme(string a,string b,string c,int dp[50][50][50]){
        if(c[0] == '\0'){//string is formed
        return 1;
    }
    
    if(dp[a.size()][b.size()][c.size()] != -1){
        return dp[a.size()][b.size()][c.size()];
    }
    
    char first = c[0];
    int ways = 0;
    for(int i=0;a[i]!='\0';i++){
        if(a[i] == first){
            ways =(ways +solveme(a.substr(i+1),b,c.substr(1),dp))%MOD;
        }
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[i] == first){
            ways =(ways + solveme(a,b.substr(i+1),c.substr(1),dp))%MOD;
        }
    }
    dp[a.size()][b.size()][c.size()] = ways%MOD;
    return ways%MOD;
}

int solve(string a,string b,string c)
{
// Write your code here .
    int dp[50][50][50];
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            for(int k=0;k<50;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    return solveme(a,b,c,dp);
}
