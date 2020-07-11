#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll power(ll no,ll times,ll p){
    if(times==0){
        return 1;
    }
    
    ll ans;
    if(times%2==0){
    ans = power(no,times/2,p);
        ans = ((ans%p)*(ans%p))%p;
    }else{
    
    ans = power(no,(times/2),p);
   // ans = ((ans%p)(ans%p)(no%p))%p;
     ans = (((((ans%p)(ans%p))%p)(no%p))%p);
        
    
    }
return ans%p;
    
}

int main() {

    ll testcases;
    cin>>testcases;
    ll p,n;
    
    while(testcases--){
    cin>>n>>p;
        
        if(n>=p){
            cout<<0<<endl;
            continue;
        }
        
        ll summ=-1;
        
        for(ll i=n+1; i<p; i++){
            ll pows = power(i,p-2,p);
        
            summ=((summ%p)*(pows%p))%p;
        }
        cout<<summ+p<<endl;
        
    }
    
}
