#include <bits/stdc++.h>
using namespace std;
int answer(bool a[],int n,int o,int c,int** ar)
{
   if(o>n||c>n)
       return 0;
    if(o==n&&c==n)
        return 1;
    if(ar[o][c]>-1)
        return ar[o][c];
    else if(o==c||a[o+c]==true)
    ar[o][c]=answer(a,n,o+1,c,ar);
    else if(o==n)
      ar[o][c]=answer(a,n,o,c+1,ar);
    else
        ar[o][c]=answer(a,n,o+1,c,ar)+answer(a,n,o,c+1,ar);
    return ar[o][c];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i;
        cin>>n>>k;
        int s[k];
        for(i=0;i<k;i++)
            cin>>s[i];
        bool a[2*n];
        memset(a, false, sizeof a);
        for(i=0;i<k;i++)
        {
            a[s[i]-1] = true;
        }
        int** ar=new int*[n+1];
        for(i=0;i<=n;i++) {
            ar[i]=new int[n+1];
            for(int j = 0;j<=n;j++)
                ar[i][j] = -1;
        }
        int ans=answer(a,n,0,0,ar);
        cout<<ans<<endl;
            
    }
    return 0;
}

