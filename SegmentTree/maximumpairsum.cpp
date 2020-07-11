#include<bits/stdc++.h>
using namespace std;
struct node{
    int max;
    int smax;
};
void buildTree(int *arr,node *tree,int start,int end,int treeNode){

    if(start==end){
        tree[treeNode].max = arr[start];
        tree[treeNode].smax = INT_MIN;
        return;
    }

    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];
    tree[treeNode].max = max(left.max,right.max);
    tree[treeNode].smax = min(max(left.max,right.smax),max(left.smax,right.max));

    return;
}
node query1(node *tree,int start,int end,int treeNode,int left,int right){
    if(start > right || end < left){
        node temp;
        temp.max = INT_MIN;
        temp.smax = INT_MIN;
        return temp;
    }
    if(start>=left && end<=right){
        if(start==end){
            node temp;
            temp.max = tree[treeNode].max;
            temp.smax = INT_MIN;
            return temp;
        }
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    node a1 = query1(tree,start,mid,2*treeNode,left,right);
    node a2 = query1(tree,mid+1,end,2*treeNode+1,left,right);
    node temp;
    temp.max = max(a1.max,a2.max);
    temp.smax = min(max(a1.max,a2.smax),max(a1.smax,a2.max));
    return temp;
}
void update(int *arr,node *tree,int start,int end,int treeNode,int index,int value){

    if(start==end){
        arr[index] = value;
        tree[treeNode].max = value;
        return;
    }

    int mid = (start+end)/2;
    if(index>mid){
        update(arr,tree,mid+1,end,2*treeNode+1,index,value);

    }else{
        update(arr,tree,start,mid,2*treeNode,index,value);
    }
    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];
    tree[treeNode].max = max(left.max,right.max);
    tree[treeNode].smax = min(max(left.max,right.smax),max(left.smax,right.max));

    return;
}
int query(node *tree,int start,int end,int treeNode,int left,int right){
    node temp = query1(tree,start,end,treeNode,left,right);
    return temp.max+temp.smax;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* tree = new node[3*n];
    buildTree(arr,tree,0,n-1,1);

    char c;
    int q,x,y;
    cin>>q;
    while(q--){
        cin>>c>>x>>y;
        if(c=='Q'){
            cout<<query(tree,0,n-1,1,x-1,y-1)<<endl;
        }
        else if(c=='U'){
            update(arr,tree,1,n,1,x,y);
        }
    }
}
