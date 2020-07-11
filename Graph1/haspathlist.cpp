#include <bits/stdc++.h>
using namespace std;
bool checkdfs( vector<vector<int>>arr,int n,int v1,int v2,bool *vis){
    vis[v1]=true;
    if(v1==v2)return true;
   // for(int i=0;i<n;i++)
    
    for(auto i : arr[v1]){
        //if(v1==i)continue;
        //if(arr[v1][i]==1){
            if(vis[i]==true)continue;
             if(!vis[i]){
                if(checkdfs(arr,n,i,v2,vis))
                return true;
        }
        }
    
    return false;
    
}
int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int> > arr( v);
        
      while(e--){
    int f,s;
    cin>>f>>s;
    arr[f].push_back(s);
      arr[s].push_back(f);
    
}
    int v1,v2;
    cin>>v1>>v2;
    
    bool *vis=new bool[v];
    for(int i=0;i<v;i++)vis[i]=false;
    if(checkdfs(arr,v,v1,v2,vis))cout<<"true";
    else cout<<"false";
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}

