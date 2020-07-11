// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>
using namespace std;
int findString(char S[], char T[]) {
    
    int n=strlen(S);
    int m=strlen(T);
    for(int i=0;i<=(n-m);i++){
        int j;
       // flag=true;
        for(j=0;j<m;j++){
            if(S[i+j]!=T[j]){
                //flag=false;
                break;
            }
        }
        
    
   // return i;
    //return j;
    
    if(j==m){
       // int ans=i-j;
        return  i;
    }}
    
    return -1;
}

