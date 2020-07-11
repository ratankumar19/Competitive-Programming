
#include<iostream>
#include<cstring>
using namespace std;
int help(char* s1, char* s2, int** dp,int m,int n) {
    
 
    if(m==0)
    { 
    dp[m][n]=n;
    return n;
    }

    if(n==0)
    { 
    dp[m][n]=m;
    return m;
    }
    //if(m==n)
      // return dp[m][n];
    int ans;
    if(s1[0]==s2[0])
        ans=help(s1 + 1,s2 + 1,dp,m-1,n-1);
    else
    {
        int op1=help(s1 + 1,s2 + 1,dp,m-1,n-1);
        int op2=help(s1 + 1,s2,dp,m-1,n);
        int op3=help(s1,s2 + 1,dp,m,n-1);
     ans=1+min(op1,min(op2,op3));
    }
    dp[m][n]=ans;
    return ans;
}

int editDistance(string s1, string s2){

    int m=s1.length();
    int n=s2.length();


char p[m];
    for (int i = 0; i < m; i++) { 
        p[i] = s1[i]; 
        
    } 
char q[n];
    for (int i = 0; i < n; i++) { 
        q[i] = s2[i]; 
        
    } 
    

    
int **dp=new int*[m+1];
    for(int i=0;i<m+1;i++)
    {
        dp[i]=new int[n+1];
    }
   return help(p,q,dp,m,n);
}

