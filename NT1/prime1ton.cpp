#include<bits/stdc++.h>
using namespace std;
bool checkprime(int n){
    int c=0;
    for(int j=1;j<=sqrt(n);j++){
        if((n%j)==0){
             if((j*j)==n){
            c+=1;
             }
       else{
            c+=2;
        }
    }}
    if(c==2)return true;
    else false;
}


int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++){
        if(checkprime(i)){
            //cout<<i<<"\n";
            count++;
        }
    }
   cout<<count<<"\n";
	// Write your code here
	return 0;
}
