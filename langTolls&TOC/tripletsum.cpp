#include <bits/stdc++.h>
using namespace std;
void FindTriplet(int arr[], int size, int x) {
    int n = size;
    sort(arr, arr + n);
    
    for(int i = 0; i < n - 2; i++){
        int firstNumber = arr[i];
        int k = i + 1;
        //int currSum = 0;
        while(k < n){
            int secNumber = arr[k] + firstNumber;
            int j = k + 1;
            while(j <= n && secNumber < x){
            int thirdNumber  = secNumber + arr[j];

            if(thirdNumber == x){
                cout << firstNumber<<" "<< arr[k]<<" "<<arr[j]<<endl;
            }
            j++;
            }
            k++;
        }
    }

}
