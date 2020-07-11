#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli n;
lli final;
lli sharma;
bool checkForMid(lli mid,lli x){
    if(mid==0)
        return false;
    if(x<=mid){
        sharma += x;
        if(sharma*2>=::n){
            if(mid<final)
                final = mid;
            return true;    
        }
        return false;
    }
    lli remaining = x-mid;
    sharma += mid;
    remaining = remaining - (remaining/10); 
    return checkForMid(mid,remaining);
}
void binSearch(lli low,lli high){
    ::sharma = 0;
    lli mid = low + (high-low)/2;
    if(low<=high){
    	if(low==high){
        checkForMid(mid,n);
        return;
	    }
	    if(checkForMid(mid,n))
	        binSearch(low,mid-1);
	    else{
	    	if(mid+1<=high)
				binSearch(mid+1,high);	
			else
				return;
		}
	}
}
int main()
{
    cin>>n;
    sharma = 0;
    final = n;
    binSearch(0,n);
    cout<<final;
	return 0;
}
