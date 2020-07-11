#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
int getmvertex(int *dis,bool *vis,int n){
    //ans me  minmium value ayega to hm jis bhi index(veretx ) ka find out krr rhe hai agr wo ans se chota hai to ans me hm usko assign kr lengee 
    int ans=-1;
    //for(int i=0;i<n;i++)
    rep(i,n){
    if( !vis[i] &&(ans==-1||(dis[i]<dis[ans]))){
        ans=i;
        
    }
        }
    return ans;
}
//rep(i,n)cin>>v[i]
void dk(int **mat,int n){
    bool *vis=new bool[n]();
    int *dis=new int[n];
    dis[0]=0;
    for(int i=1;i<n;i++){
        dis[i]=INT_MAX;
    }
    //for(int i=0;i<n-1;i++)
    rep(i,n){
            int minv=getmvertex(dis,vis,n);
            vis[minv]=true;
            //for(int j=0;j<n;j++)
            rep(j,n){
            if(mat[minv][j]!=0 &&!vis[j]){
               if(dis[minv]+mat[minv][j]<dis[j])
                   dis[j]=dis[minv]+mat[minv][j];
                
            }
            }
        
    }
   // for(int i=0;i<n;i++)
        rep(i,n)
        cout<<i<<" "<<dis[i]<<"\n";

}


int main()
{
int n,e;
cin >> n>> e;
int **mat=new int*[n];
    //for(int i=0;i<n;i++)
    		rep(i,n){
        mat[i]=new int[n];
        
        //for(int j=0;j<n;j++)
        rep(j,n){
            mat[i][j]=0;
        }
    }
   // for(int i=0;i<e;i++)
    rep(i,e){
        int f,s,w;
        cin>>f>>s>>w;
        mat[f][s]=w;
        mat[s][f]=w;
    }
    dk(mat,n);
   
  return 0;
}

