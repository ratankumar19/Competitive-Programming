#include<bits/stdc++.h>
using namespace std;
int MaxZero(int **in,int **dp,int r,int c)
{
    for(int i=0;i<c;i++)
    {
        if(in[0][i]==0)
            dp[0][i]=1;
        else
           dp[0][i]==0;  
    }
     for(int i=0;i<r;i++)
    {
        if(in[i][0]==0)
            dp[i][0]=1;
        else
           dp[i][0]==0;  
    }
    
     for(int i=1;i<r;i++)
    {
     for(int j=1;j<c;j++)
    {
         if(in[i][j]==1)
             dp[i][j]=0;
         else
         dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
     }}
    int max=dp[0][0];
    
     for(int i=0;i<r;i++)
    {
     for(int j=0;j<c;j++)
    {
         if(max<dp[i][j])
            max=dp[i][j];
     }}
    return max;
    
}





int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int **dp=new int*[row];
    for(int i=0;i<row;i++)
    {
        dp[i]=new int[col];
            for(int j=0;j<col;j++)
                dp[i][j]=0;
    }
    return MaxZero(arr,dp,row,col);
        
    
}
