#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int a=0;
    int s=0;
    int p=0;
    for(int i=0;i<n;i++){
        if(str[i]=='a')
            a=a+1;
        else if(str[i]=='s')
            s=s+1;
        else if(str[i]=='p')
            p=p+1;
    }
    cout<<a<<" "<<s<<" "<<p;
	return 0;
}
