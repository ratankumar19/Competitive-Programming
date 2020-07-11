int sum(int input[], int n ) {
  
    int  ans = input[0];
    if(n==1)
    {
        
        return ans;   
    }
   
    return ans+ sum(input+1,n-1);
  

}

