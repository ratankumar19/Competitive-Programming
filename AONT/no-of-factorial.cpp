#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int primes[MAX];
int arr[11][MAX];
void seive(){
    memset(primes,0,MAX);
    for(int i=2;i<10001;i++){
        if(primes[i]==0){
            for(int j=i;j<=MAX;j+=i){
                primes[j]++;
                
            }
        }
    }
    }
void helper(){
    seive();
    for(int i=0;i<11;i++){
        for(int j=0;j<MAX;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<MAX;j++){
            if(primes[j]==i){
                arr[i][j]=arr[i][j-1]+1;
            }else
                 arr[i][j]=arr[i][j-1];
           
        }
    }
    
}


int main(){
    
    helper();
    int t;
    cin>>t;
        while(t--){
            int a,b,n;
            cin>>a>>b>>n;
            int ans=arr[n][b]-arr[n][a-1];
            cout<<"finals ans"<<ans<<"\n";
        }
	// Write your code here
	return 0;
}
