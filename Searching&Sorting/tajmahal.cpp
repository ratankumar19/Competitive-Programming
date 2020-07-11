#include<bits/stdc++.h>
using namespace std;
bool check(int A[], int t, long long time){
    for (int i=0;i<t;i++){
        if ((i+time*t)>=A[i]){
           // return i+1;
        }return true;
    }return false;
}
int main()
{
    int t;
    cin>>t;
    int A[t];
    for (int i=0;i<t;i++){
        cin>>A[i];
    }
    int count=0;
    int i=0;
    while(A[i]-count>=1)
    {
      count++;
        i=(i+1)%t;
        
    }
    cout<<count+1<<"\n";
   	return 0;
}

