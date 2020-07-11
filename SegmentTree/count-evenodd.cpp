#include<iostream>
using namespace std;
void buildTree(int *arr,int *tree,int start,int end,int treeNode){
    if(start==end){
        if(arr[start]%2==0)
            tree[treeNode] = 1;
        else
            tree[treeNode] = 0;
        return ;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
}
void update(int *arr,int *tree,int start,int end,int treeNode,int index,int value){
    
    if(start==end){
        arr[index] = value;
        if(value%2==0)
            tree[treeNode] = 1;
        else
            tree[treeNode] = 0;
        return;
    }

    int mid = (start+end)/2;
    if(index>mid){
        update(arr,tree,mid+1,end,2*treeNode+1,index,value);

    }else{
        update(arr,tree,start,mid,2*treeNode,index,value);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];

}
int query(int *tree,int start,int end,int treeNode,int left,int right){
    
    //Outside
    if(start > right || end < left)
        return 0;
    //Inside
    if(start>=left && end<=right)
        return tree[treeNode];
    //Partial
    int mid = (start+end)/2;
    int a1 = query(tree,start,mid,2*treeNode,left,right);
    int a2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    
    return a1+a2;

}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *tree = new int[4*n];
    buildTree(arr,tree,0,n-1,1);
    int q,z,x,y;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>z>>x>>y;
        if(z==0){
            update(arr,tree,0,n-1,1,x-1,y);
        }
        else if(z==1){
            cout<<query(tree,0,n-1,1,x-1,y-1)<<endl;
        }
        else if(z==2){
            cout<<y-x+1-query(tree,0,n-1,1,x-1,y-1)<<endl;
        }
    }


    return 0;
}
