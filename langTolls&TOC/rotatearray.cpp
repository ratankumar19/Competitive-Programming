// arr - input array
// size - size of array
// d - array to be rotated by d elements
#include<utility>
#include<cmath>
void Rotate(int arr[], int d, int size) {
   
    
while(d--)
{
    for(int i=0;i<size-1;i++)
    {
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
       
    }
}
}	

