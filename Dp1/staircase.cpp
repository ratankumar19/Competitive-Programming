long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    long int *in=new long int[n+1];
    in[0]=1;
    in[1]=1;
    in[2]=2;
    for(int i=3;i<=n;i++)
        in[i]=in[i-1]+in[i-2]+in[i-3];
     long op=in[n];
    delete []in;
    return op;
}

