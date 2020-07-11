#include <bits/stdc++.h>
//#define  pb push_back
using namespace std;
vector<int>* getdfs( vector<vector<int>>arr,int n,int st,int ed,bool *vis){
    vis[st]=true;
    if(st==ed){
        vector<int>* output = new vector<int>();
        output->push_back(ed);
        return output;
         }
    //for(int i=0;i<n;i++)
     for(auto i : arr[st]){
       // if(i==st)continue;
        //if(arr[st][i]==1){
            if(vis[i]==true)continue;
            //vis[i]=true;
            vector<int>* smallpath=getdfs(arr,n,i,ed,vis);
            if(smallpath!=NULL)
            {
                smallpath->push_back(st);
                return smallpath;
            }
            }
    
    
    return NULL;
    
}

int main()
{
  int v, e;//tempX, tempY;
  cin >> v>> e;
    //int **arr=new int*[v];
    vector<vector<int>>arr(v);
   /* for(int i=0;i<v;i++){
        arr[i]=new int[v];
        for(int j=0;j<v;j++)
            arr[i][j]=0;
    };*/
    while(e--){
        int v1,v2;
        cin>>v1>>v2;
        arr[v1].push_back(v2);
        arr[v2].push_back(v1);
        //arr[f].push_back(s);
        //arr[s].push_back(f);
        //arr[v1][v2]=1;
        //arr[v2][v1]=1;
    }
    int st,ed;
    cin>>st>>ed;
    bool *vis=new bool[v];
    for(int i=0;i<v;i++)vis[i]=false;
    vector<int>* vec=getdfs(arr,v,st,ed,vis);
    
    if(vec!=NULL)        
        for(int i=0;i<vec->size();i++)
            cout << vec->at(i) << " " ;


  return 0;
}
