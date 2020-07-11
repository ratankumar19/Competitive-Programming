
using namespace std;
#include<unordered_map>
void PairSum(int *arr, int n) {	 
	unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        int temp=-1*arr[i];
       // if(m.count(temp)>0){
        if(m.find(temp)!=m.end()) 
        {
        int temp1=(m.find(temp))->second*(m.find(arr[i]))->second;
            while(temp1--){
                cout<<min(temp,arr[i])<<" "<<max(temp,arr[i])<<endl;
            }
            m.erase(temp);
            m.erase(arr[i]);
        }
    }
}
