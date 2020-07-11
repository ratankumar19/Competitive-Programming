int turnOffFirstSetBit(int n){
    n=n&(n-1);
    return n;
}
