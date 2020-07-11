#include <bits/stdc++.h>
using namespace std;
typedef long long l;
l kadane(l dp[],l r)
{
    l max_sum=0;
    l curr_sum=0;
    l max1 = INT_MIN;
    for(l i=0;i<r;i++)
    {
       
        curr_sum+=dp[i];
        max1 = max(max1,dp[i]);
        if(curr_sum<0)
              curr_sum=0;
        if(curr_sum>max_sum)
            max_sum=curr_sum;
          
    }
   
    if(max1<0) return max1;
    return max_sum;
}
l findSum(l **matrix,l r,l c)
{
    l maxSum=INT_MIN;
    for(l lt=0;lt<c;lt++)
    {
         l dp[r]={0};
        for(l rt=lt;rt<c;rt++)
        {
           
            for(int i=0;i<r;i++)
            {
                dp[i]+=matrix[i][rt];
            }
        
        l sum=kadane(dp,r);
        if(maxSum<sum)
            maxSum=sum;
    }}
    return maxSum;
}


int main()
{
    l r,c;
    cin>>r>>c;
  
    l **matrix=new l*[r];
    for(int i=0;i<r;i++)
    {
        matrix[i]=new l [c];
        for(l j=0;j<c;j++)
        {
        cin>>matrix[i][j];
    }}
  
    cout<<findSum(matrix,r,c)<<"\n";
    return 0;
}
