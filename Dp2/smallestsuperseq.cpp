int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  int** dp=new int*[len1+1];
    int i,j;
    for(i=0;i<=len1;i++)
        dp[i]=new int[len2+1];
    for(i=len1;i>=0;i--)
        dp[i][len2]=len1-i;
        for(i=len2;i>=0;i--)
        dp[len1][i]=len2-i;
     for(i=len1-1;i>=0;i--)
     {
         for(j=len2-1;j>=0;j--)
         {
             if(str1[i]==str2[j])
                 dp[i][j]=1+dp[i+1][j+1];
             else
                 dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
         }
     }
    int ans=dp[0][0];
    for(i=0;i<=len1;i++)
        delete [] dp[i];
    delete dp;
    return ans;
}
