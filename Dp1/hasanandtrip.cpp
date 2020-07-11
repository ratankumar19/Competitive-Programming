#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    double dp[n];
    for(int i=0;i<n;i++){dp[i]=INT_MIN;}
    dp[0]=arr[0][2];
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            double dist=sqrt(pow(arr[j][0]-arr[i][0],2)+pow(arr[j][1]-arr[i][1],2));
            double happy=arr[i][2]+dp[j]-dist;
            if(happy>dp[i])
            {
                dp[i]=happy;
            }
            
        }
    }
    cout<<fixed<<setprecision(6)<<dp[n-1];
    return 0;
}

