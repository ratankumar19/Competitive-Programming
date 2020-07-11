
#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr,int *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
     //tree[treeNode] = (tree[2*treeNode]+tree[2*treeNode+1]);
}
void update(int *arr,int *tree,int start,int end,int treeNode,int index,int value){
    
    if(start==end){
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start+end)/2;
    if(index>mid){
        update(arr,tree,mid+1,end,2*treeNode+1,index,value);

    }else{
        update(arr,tree,start,mid,2*treeNode,index,value);
    }
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);

}
int query(int *tree,int start,int end,int treeNode,int left,int right){
    
    //Outside
    if(start > right || end < left){
        // cout<<"OUTSIDE\n";
        return INT_MAX;
    }
    //Inside
    if(start>=left && end<=right){
        // cout<<"INSIDE\n";
        return tree[treeNode];
    }
    //Partial
    // cout<<"PARTIAL\n";
    int mid = (start+end)/2;
    int a1 = query(tree,start,mid,2*treeNode,left,right);
    int a2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    
    return min(a1,a2);

}
int main(){
    int n,q;
    cin>>n>>q;
    int *arr = new int[n];
    char c;
    int x,y;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *tree = new int[4*n];//by deafult conatains 0
    buildTree(arr,tree,0,n-1,1);
    for(int i=0;i<q;i++){
        cin>>c>>x>>y;
      /*  if(c=='q'){
            cout<<query(tree,0,n-1,1,x-1,y-1)<<endl;
        }
        else if(c=='u'){
            update(arr,tree,1,n,1,x,y);
        }
    }*/
    }for(int i=0;i<4*n;i++)
            cout<< i<<"value of" <<tree[i]<<"\n";
    return 0;
}
