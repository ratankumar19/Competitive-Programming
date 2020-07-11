#include <bits/stdc++.h>
#include<queue>
using namespace std;
void printbfs(int **arr,int n,int sv){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){visited[i]=false;}
    queue <int> pv;
    pv.push(sv);
    visited[sv]=true;
    while(!pv.empty()){
        int cv=pv.front();
       
        pv.pop();
         cout<<cv<<" ";
        for(int i=0;i<n;i++){
            if(i==cv){continue;}
            if(arr[cv][i]==1 && !visited[i]){
                pv.push(i);
                visited[i]=true;
            }
            
        }
    }
    
    
}
int main() {
    int v, e;
    cin >> v >> e;
    
    
    int **arr=new int*[v];
    for(int i=0;i<v;i++){
        arr[i]=new int [v];
        for(int j=0;j<v;j++)
            arr[i][j]=0;
        
    }
  
    while(e--){
        int f,s;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;
        
    }
    printbfs(arr,v,0);
    
    
  return 0;
}

