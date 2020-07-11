#include <iostream>
using namespace std;
bool checkdfs(int **arr,int n,int v1,int v2,bool *vis){
    vis[v1]=true;
    if(v1==v2)
        return true;
    for(int i=0;i<n;i++){
        if(i==v1)
            continue;
        if(arr[v1][i]==1){
            if(vis[i]==true)
                continue;
            
                if(checkdfs(arr,n,i,v2,vis))
                return true;
            
        }
    }
    return false;
    //logic;
}
int main() {
    int v, e;
    cin >> v >> e;
    int **arr=new int *[v];
    for(int i=0;i<v;i++)
    {
        arr[i]=new int[v];
        for(int j=0;j<v;j++)
            arr[i][j]=0;
    }
while(e--){
    int f,s;
    cin>>f>>s;
    arr[f][s]=1;
    arr[s][f]=1;
    
}
    int v1,v2;
    cin>>v1>>v2;
    
    bool *vis=new bool[v];
    for(int i=0;i<v;i++)
        vis[i]=false;
    if(checkdfs(arr,v,v1,v2,vis))
        cout<<"true";
    else
        cout<<"false";
  

  return 0;
}

