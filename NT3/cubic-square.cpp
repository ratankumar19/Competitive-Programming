#include<bits/stdc++.h>
using namespace std;
int main() {
    
    long long testcases;
    cin>>testcases;
    
    while(testcases--){
        long long a,mod;
        string b;
        
        cin>>a>>b>>mod;
        
        long long result = 1;
        
        long long n = b.size();
        for(int i=n-1; i>=0; i--){
            if(b[i]=='1'){
                result = (result*a)%mod;
            }else if(b[i]=='2'){
                result = (((result*a)%mod)*a)%mod;
            }
        a = (((a*a)%mod)*a)%mod;
        }
        cout<<result<<endl;
        
    }
    
    
    
}
