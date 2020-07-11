#include<iostream>
using namespace std;
bool fault;
bool checkPlz(int *arr,int n){
    int temp;
    bool swapped = false;
    bool notSorted = false;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            if(abs(arr[i]-arr[i+1])==1){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
            else{
                ::fault = true;
                swapped = false;
                notSorted = true;
                return false;
            }
        }
    }
    if(swapped)
        return checkPlz(arr,n);
    return !notSorted;
}
int main(){
    int t,i,n;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        int *a = new int[n];
        for(int j=0;j<n;j++)
            cin>>a[j];
        bool check = checkPlz(a,n);
        if(check)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
