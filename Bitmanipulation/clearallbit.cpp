int clearAllBits(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
 int mask= (1<<i)-1;
    n=n&mask;
    return n;
}

