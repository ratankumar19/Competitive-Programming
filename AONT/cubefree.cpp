#include <bits/stdc++.h>
using namespace std;
#define size 1000000
int mark[size+1];

void sieve()
{
    memset(mark,0,size+1);
     for(int i=2;i<=100;i++){
         if(mark[i]==0){
          for(int j=i*i*i;j<=size;j+=i*i*i)
               mark[j]=-1;
         }}
     int countv=1;      
     for(int i=1;i<=size;i++)      
          if(mark[i]==0)
               mark[i]=countv++;
}
int main() {
    int t;
    cin>>t;
    sieve();
        for(int i=1; i<=t; i++){
            int n;
            cin>>n;
             if(mark[n]==-1)
        		 cout<< "Case " << i << ": "<<"Not Cube Free"<<"\n";
            else 
                cout<< "Case " << i << ": "<<mark[n]<<"\n";
            
        }
    return 0;

    }
