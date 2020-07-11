#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> components;
void printDFS(int n,int e,int **edge,int *visited,vector<int> &vec ){
    vec.push_back(e);
    visited[e] = 1;
    for(int i=0;i<n;i++){
        if(i==e)
            continue;
        if(edge[e][i]==1){
            if(visited[i] == 1)
                continue;
            printDFS(n,i,edge,visited,vec);
    	}
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    int **edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++)
            edge[i][j] = 0;
    }
    int v1,v2;
    for(int i=0;i<e;i++){
        cin>>v1>>v2;
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }
    
    int *visited = new int[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    for(int i=0;i<n;i++){
        vector<int> vec;//= new vector<int>();
        if(visited[i]==0 ){
           printDFS(n,i,edge,visited,vec);
            sort(vec.begin(),vec.end());
           components.push_back(vec);  
        }
    }
     for(int i=0;i<components.size();i++){
        for(int j=0;j<components[i].size();j++){
            cout<<components[i][j]<<" ";
        }
        cout<<endl;
    }
    delete []visited;
    return 0;
}
