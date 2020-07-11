#include<bits/stdc++.h>
using namespace std;

long long  merge(int A[],int first,int mid ,int last)
{
//cout<<"first value is" <<first<<"\n";
//cout<<"mid value is" <<mid<<"\n";
//cout<<"last value is" <<last<<"\n";


    int i=first;
    int j=mid;
    int k=0;
    int temp[last-first+1];
        long long sum=0;
    while(i<mid && j<=last)
    {
        if(A[i]>=A[j])
        {
            temp[k++]=A[j++];
        }
        else
        {
      
            sum=sum+A[i]*(last-j+1);
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
    return sum;
    
}

long long merge_sort(int A[],int l,int r)
{
    long long count=0;
    
        if(l<r)
        {
            int mid=(l+r)/2;
            long long lcount= merge_sort(A,l,mid);
           // cout<<"lcount is"<<lcount<<endl;
            long long rcount= merge_sort(A,mid+1,r);
           // cout<<"rcount is"<<rcount<<endl;
            long long mcount= merge(A,l,mid+1,r);
            //cout<<"mcount is"<<mcount<<endl;
            return mcount+lcount+rcount;
        }
    
    return count;
    
}
int main() {
int t;
 //cout<<"no of case:"<<endl;
    cin>>t;
    while(t--)
    {
        int n;
         //cout<<"size is"<<endl;
         cin>>n;
    int arr[n];
     //cout<<"array ; is"<<endl; 
        for(int i=0;i<n;i++)
        { cin>>arr[i];}
       // long long ans=
            cout<<merge_sort(arr,0,n-1)<<"\n";
   
	// Write your code here
    }
    return 0;
}
