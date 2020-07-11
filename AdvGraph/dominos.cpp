#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void dfs(vector<int> **graph, int source, bool *isVisited, stack<int> &s){
    isVisited[source] = true;
    for(int i = 0; i < graph[source]->size(); i++){
        int v = graph[source]->at(i);
        if(!isVisited[v]){
            dfs(graph, v, isVisited, s);
        }
    }

    s.push(source);
}

void dfs2(vector<int> **graph, int source, bool *isVisited){
    isVisited[source] = true;

    for(int i = 0; i < graph[source]->size(); i++){
        int v = graph[source]->at(i);
        if(!isVisited[v]){
            dfs2(graph, v, isVisited);
        }
    }
}

void kosaraju(vector<int> **graph, int n){
    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    stack<int> s;
    for(int i = 0; i < n; i++){
        if(!isVisited[i]){
            dfs(graph, i, isVisited, s);
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) isVisited[i] = false;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!isVisited[v]){
            count++;
            dfs2(graph, v, isVisited);
        }
    }

    cout << count << endl;
}

int main(){
   // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    int n, m;
    while(t--){
        cin >> n >> m;

        vector<int> **graph = new vector<int> *[n];
        for(int i = 0; i < n; i++) graph[i] = new vector<int>;

        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            graph[u-1]->pb(v-1);
        }

        kosaraju(graph, n);
    }
}
