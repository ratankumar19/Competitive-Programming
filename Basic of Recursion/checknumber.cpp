bool checkNumber(int input[], int size, int x) {
  
if(size == 0)return false;

if(input[0] == x)
return true;
bool small=checkNumber(input+1,size-1,x);
return small;
}

