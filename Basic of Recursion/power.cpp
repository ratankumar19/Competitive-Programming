int power(int x, int n) {
  if(n==0)
  {
      return 1;
  }
    int small_output=x*power(x,n-1);
    return small_output;
}

