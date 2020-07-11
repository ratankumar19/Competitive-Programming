// arr - input array
// n - size of array
#include<bits/stdc++.h>
using namespace std; 
int minAbsoluteDiff(int arr[], int n) {
    sort(arr,arr+n);
    int x=INT_MAX;
    for(int i=0;i<n-1;i++){
        int d=arr[i+1]-arr[i];
        if(x>d){
            x=d;
        }
        
    }
    return x;

}

