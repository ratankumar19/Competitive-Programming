#include <string>
using namespace std;
string combination[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
    if(num==0){
        return 1;
    }
    string ans[10000];
    string smallString = combination[num%10];
    int small=keypad(num/10,ans);
    int k=0;
    for(int i=0;i<small;i++)
    {     
        for(int j=0;j<smallString.size();j++)
        {
            output[k] = ans[i] + smallString[j];
            k++;
        }
    }
    return k;
}

