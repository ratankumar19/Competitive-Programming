#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lcs(string s1, string s2)
{

  
 int m=s1.length();
     int n=s2.length();
    int **dp=new int*[m+1];
        for(int i=0;i<m+1;i++)
        { dp[i]=new int[n+1];}
    
    for(int i=0;i<m+1;i++)
    {  dp[i][0]=0;}
    
            
 
    for(int i=0;i<n+1;i++)
    {    dp[0][i]=0;}
    
     
    for(int i=1;i<m+1;i++)
    {
    for(int j=1;j<n+1;j++)
    {
        if(s1[m-i]==s2[n-j])
            dp[i][j]=1+dp[i-1][j-1];
        else
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        
    }}  
    
    int ans=dp[m][n];
    for(int i=0;i<m+1;i++)
        delete []dp[i];
        return ans;
    } 
            
    
            
    
            




