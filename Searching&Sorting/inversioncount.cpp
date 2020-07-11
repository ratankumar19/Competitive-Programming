
long long  merge(int A[],int first,int mid ,int last)
{
    int i=first;
    int j=mid;
    int k=0;
    int temp[last-first+1];
        long long count1=0;
    while(i<mid && j<=last)
    {
        if(A[i]<=A[j])
        {
            temp[k++]=A[i++];
        }
        else
        {
       temp[k++]=A[j++];
            count1++;
                    
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
    return count1;
    
}
long long merge_sort(int A[],int l,int r)
{
    long long count=0;
    
        if(l<r)
        {
            int mid=(l+r)/2;
            long long lcount= merge_sort(A,l,mid);
            long long rcount= merge_sort(A,mid+1,r);
            long long mcount= merge(A,l,mid+1,r);
            return mcount+lcount+rcount;
        }
    
    return count;
    
}

long long solve(int A[], int n)
{
    long long ans=merge_sort(A,0,n-1);
    return ans;
    
	// Write your code here.
}
