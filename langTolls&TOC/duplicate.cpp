#include<map>
using namespace std;
int MissingNumber(int arr[], int size){
   
map<int,int>m;
    for(int i=0;i<size;i++)
    {
        m[arr[i]]= m[arr[i]]+1;
        
        
    }
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second>=2)
            return it->first;
    }
}

