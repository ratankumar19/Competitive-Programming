#include <iostream>
using namespace std;

int coin_change(int n, int* d, int numD, int** output) {
	if (n == 0) {
		output[n][numD] = 1;
		return 1;
	}
	if (n < 0) {
		output[n][numD] = 0;
		return 0;
	}
	if (numD == 0) {
		return 0;
	}
	if (output[n][numD] > -1) {
		return output[n][numD];
	}
	int first = 0;
	if(d[0] <= n)
		first = coin_change(n - d[0], d, numD, output);
	int second = coin_change(n, d + 1, numD - 1, output);
	output[n][numD] = first + second;
	return first + second;
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){ 
int** arr;
arr = new int* [value+1];
for(int i=0;i<value+1;i++){
    arr[i]=new int[numDenominations+1];   
    for(int j=0;j<numDenominations+1;j++)
        arr[i][j]=-1;
}
int ans = coin_change(value, denominations, numDenominations,arr);
return ans;
}
