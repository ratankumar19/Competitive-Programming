#include<bits/stdc++.h>
using namespace std;
int main() {
int t;
    cin>>t;
    while(t--){
        long long m;
        cin>>m;
        int s=0;
        while(m>0)
        {
            int temp=m%10;
           
            s=s+temp;
             m=m/10;
        }
        
        
       //int ans=getSum(m);
        
        cout<<s<<"\n";
       
        
    }     
        return 0;
	
}
