#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum) 
{ 
	int curr_sum, i, j,k; 

	for (i = 0; i < n; i++) 
	{ 
		curr_sum = arr[i]; 


		for (j = i+1; j <= n; j++) 
		{ 
			if (curr_sum == sum) 
			{ 
				//printf ("Sum found between indexes %d and %d", i, j-1); 
				cout<<"true"<<"\n";
				for(k=i;k<j;k++)
				{
				cout<<arr[k]<<" ";				
				}
				return 1; 
			} 
			if (curr_sum > sum || j == n) 
				break; 
		curr_sum = curr_sum + arr[j]; 
		} 
	} 

	cout<<"false"<<"\n";
	return 0; 
} 

int main() 
{ 
	int m,sum;
    cin>>m>>sum;
    int *a=new int[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        
    }
    subArraySum(a, m, sum); 
	return 0; 
} 

