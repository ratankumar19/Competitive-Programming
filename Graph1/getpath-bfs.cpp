#include<iostream>
#include<queue>
#include<map>
using namespace std;
void print(int n,int e,int **edge,int ed){
    queue <int> pending;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    	visited[i] = false;
    
    map <int,int> whoInsertedwho;
    
    pending.push(e);
    visited[e] = true;
    int current;
    int last = e;
    bool flag=false;
    while(!pending.empty() && !flag){
    	current = pending.front();
    	pending.pop();
    	// cout<<current<<" ";
    	for(int i=0;i<n;i++){
    		if(edge[current][i]==1 && !visited[i]){
    			pending.push(i);
    		    whoInsertedwho.insert(pair<int, int>(i,current));
    			visited[i] = true;
			}
            if(current==ed)
            {
                flag=true;
                break;
                
                
            }
               //ha last = current;
		}
	}

  //  if(last!=e){
  //
    if(flag==false){
        return;
    }
    else{
        while(current!=e){
            cout<<current<<" ";
            current = whoInsertedwho.at(current);
        }
    
    cout<<e<<" ";
        //cout<<last;
    }
	
	delete []visited;
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
    int st,ed;
    cin>>st>>ed;
    print(n,st,edge,ed);

    return 0;
}
