int lastIndex(int input[], int size, int x) {
  



    if(size == 0)
    {
        return -1;
    }
   
     if(input[size-1] == x)
    {
        return size-1;
    }
    int ans =lastIndex(input,size-1,x);
    //return ans ;
    /*if(ans==-1)
    {
        return -1;
    }
    else
        return ans+1;*/
    
    
}

