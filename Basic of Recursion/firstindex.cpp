int firstIndex(int input[], int size, int x) {
 

    if(size == 0 ||input[0] != x )
    {
        return -1;
    }
    if(input[0] == x)
    {
        return 0;
    }
    
    int ans =firstIndex(input+1,size-1,x);
    return ans+1;
    
    
}

