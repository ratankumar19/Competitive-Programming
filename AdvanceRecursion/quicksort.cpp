#include <iostream>
using namespace std;
void merge(int A[],int first,int mid ,int last)
{
	int i=first;
    int j=mid;
    int k=0;
    int temp[last-first+1];
       
    while(i<mid && j<=last)
    {
        if(A[i]>=A[j])
        {
            temp[k++]=A[j++];
        }
        else
        {
             temp[k++]=A[i++];
     }
    } 
     while(i<mid)
    {
        temp[k++]=A[i++];
    }
    while(j<=last)
        {
        temp[k++]=A[j++];
    }
    for(int p=first,k=0;p<=last;p++,k++)
    {
        A[p]=temp[k];
    }
   
}      
        
void merge_sort(int A[],int l,int r)
{
   if(l>=r){return ;}
    else
    {
            int mid=(l+r)/2;
          merge_sort(A,l,mid);
            merge_sort(A,mid+1,r);
       merge(A,l,mid+1,r);
    }
}
void mergeSort(int input[], int size){
	int l=0;
    int r=size-1;
    merge_sort( input,l,r);

}

