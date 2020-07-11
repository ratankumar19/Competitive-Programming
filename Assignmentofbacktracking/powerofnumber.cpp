#include<iostream>
using namespace std;
int getVal(int x,int n){
    if(n==0)
        return 1;
    return x*getVal(x,n-1);
}
int main() {
	// Write your code here
	int x,n;
    cin>>x>>n;
    cout<<getVal(x,n)<<endl;
}
