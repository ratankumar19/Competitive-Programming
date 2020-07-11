#include<bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *weight,int n){
    int minVert = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && ((minVert == -1) || (weight[minVert]>weight[i]))){
            minVert = i;
        }
    }
    return minVert;
}
void prims(int **edges,int n){
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weight = new int[n];
    for(int i=0;i<n;i++)
        weight[i] = INT_MAX;
    parent[0] = -1;
    weight[0] = 0;

    for(int i=0;i<n-1;i++){
        int minVert = getMinVertex(visited,weight,n);
        visited[minVert] = true;

        for(int j=0;j<n;j++){
            if(edges[minVert][j]!=0 && !visited[j]){
                if(weight[j]>edges[minVert][j]){
                    weight[j] = edges[minVert][j];
                    parent[j] = minVert;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(parent[i] == -1)
            continue;
        if(parent[i]<i)
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        else
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    prims(edges,n);
    
    
}
