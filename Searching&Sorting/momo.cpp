#include<bits/stdc++.h>
using namespace std;
typedef long long l;
int main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
  l d;
    cin>>d;
  l amt[d];
     for(l i=0;i<d;i++)
    {
        cin>>amt[i];
    }
    int *arr=new int[n];
    
     /*for(int i=0;i<n;i++)
     {
         int sum=0;
          for(int j=0;j<=i;j++)
          {
               sum+=price[j];

              arr[i]=sum;
}*/
    arr[0]=price[0];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i-1]+price[i];
    }
    
    
    for(l i=0;i<d;i++)
    {
         int left = 0, right = n; 

	int mid;
        l key=amt[i];
	while (left < right) { 
		mid = (right + left)/2; 

		// Check if key is present in array 
		if (arr[mid] == key) { 
			// If duplicates are present it returns 
			// the position of last element 
			/*while (mid + 1 < n && arr[mid + 1] == key) 
				mid++;*/ 
			break; 
		} 

		// If key is smaller, ignore right half 
		else if (arr[mid] > key) 
			right = mid; 

		// If key is greater, ignore left half 
		else
			left = mid + 1; 
	} 

	// If key is not found in array then it will be 
	// before mid 
	    if(arr[mid] > key) 
		mid--; 

	// Return mid + 1 because of 0-based indexing 
	// of array 
cout<<mid+1<<" "<< key-arr[mid]<<"\n";
   
        }
    
	return 0;
}

