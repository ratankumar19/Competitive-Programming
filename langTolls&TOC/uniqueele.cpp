
#include<bits/stdc++.h>
using namespace std;
int FindUnique(int arr[], int size){
    sort(arr,arr+size);
    if(arr[size-1]!=arr[size-2])
    {
        return arr[size-1];
    }
    for(int i=1;i<size;i=i+2)
    {
        if(arr[i]!=arr[i-1])
        {
            return arr[i-1];
        }
    }
}
