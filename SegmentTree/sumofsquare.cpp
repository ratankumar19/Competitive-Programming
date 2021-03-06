#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void buildtree(ll *a,pair<ll,ll> *tree,int si,int ei,int node) {
    if(si==ei) {
        tree[node].first=a[si]*a[si];
        tree[node].second=a[si];
        return;
    }
    int mid=(si+ei)/2;
    buildtree(a,tree,si,mid,2*node);
    buildtree(a,tree,mid+1,ei,2*node+1);
 
    tree[node].first=tree[2*node].first+tree[2*node+1].first;
    tree[node].second=tree[2*node].second+tree[2*node+1].second;
}
 
void update(pair<ll,ll> *tree,pair<ll,ll> *lazy,int si,int ei,int node,int left,int right,int type,ll value) {
    if(si>ei)
        return;
    if(lazy[node].first!=0) {
        if(lazy[node].second!=2) {
            tree[node].first+=(2*lazy[node].first*tree[node].second)+((ei-si+1)*lazy[node].first*lazy[node].first);
            tree[node].second+=(ei-si+1)*lazy[node].first;
 
            if(si!=ei) {
                lazy[2*node].first+=lazy[node].first;
                lazy[2*node+1].first+=lazy[node].first;
            }
 
            lazy[node].first=0;
            lazy[node].second=0;
        }
 
        else {
            tree[node].first=(ei-si+1)*lazy[node].first*lazy[node].first;
            tree[node].second=(ei-si+1)*lazy[node].first;
            if(si!=ei) {
                lazy[2*node].second=2;
                lazy[2*node+1].second=2;
                lazy[2*node].first=lazy[node].first;
                lazy[2*node+1].first=lazy[node].first;
            }
            lazy[node].first=0;
            lazy[node].second=0;
        }
    }
 
    if(si>right || ei<left)
        return;
    if(si>=left && ei<=right) {
        if(type==1) {
            tree[node].first=tree[node].first+(2*value*tree[node].second)+((ei-si+1)*value*value);
            tree[node].second+=(ei-si+1)*value;
 
            if(si!=ei) {
                lazy[2*node].first+=lazy[node].first;
                lazy[2*node+1].first+=lazy[node].first;
            }
            return;
        }
        else {
            tree[node].first=(ei-si+1)*value*value;
            tree[node].second=(ei-si+1)*value;
            if(si!=ei) {
                lazy[2*node].second=2;
                lazy[2*node+1].second=2;
                lazy[2*node].first=value;
                lazy[2*node+1].first=value;
            }
            return;
        }
    }
    int mid=(si+ei)/2;
    update(tree,lazy,si,mid,2*node,left,right,type,value);
    update(tree,lazy,mid+1,ei,2*node+1,left,right,type,value);
    tree[node].first=tree[2*node].first+tree[2*node+1].first;
    tree[node].second=tree[2*node].second+tree[2*node+1].second;
    return;
}
 
ll query(pair<ll,ll> *tree,pair<ll,ll> *lazy,int si,int ei,int node,int left,int right) {
 
    if(lazy[node].first!=0) {
        if(lazy[node].second!=2) {
            tree[node].first=tree[node].first+(2*lazy[node].first*tree[node].second)+((ei-si+1)*lazy[node].first*lazy[node].first);
            tree[node].second+=(ei-si+1)*lazy[node].first;
 
            if(si!=ei) {
                lazy[2*node].first+=lazy[node].first;
                lazy[2*node+1].first+=lazy[node].first;
            }
 
            lazy[node].first=0;
            lazy[node].second=0;
        }
 
        else {
            tree[node].first=(ei-si+1)*lazy[node].first*lazy[node].first;
            tree[node].second=(ei-si+1)*lazy[node].first;
            if(si!=ei) {
                lazy[2*node].second=2;
                lazy[2*node+1].second=2;
                lazy[2*node].first=lazy[node].first;
                lazy[2*node+1].first=lazy[node].first;
            }
            lazy[node].first=0;
            lazy[node].second=0;
        }
    }
    if(si>right || ei<left)
        return 0;
    if(si>=left && ei<=right)
        return tree[node].first;
    int mid=(si+ei)/2;
    ll ans1=query(tree,lazy,si,mid,2*node,left,right);
    ll ans2=query(tree,lazy,mid+1,ei,2*node+1,left,right);
    return ans1+ans2;
}
 
int main() {
    int t;
    cin>>t;
  int count=1;
    while(t--) {
      cout<<"Case "<<count++<<':'<<endl;
        int n,q;
        cin>>n>>q;
        ll *a=new ll[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        pair<ll,ll> *tree=new pair<ll,ll>[4*n];
        buildtree(a,tree,0,n-1,1);
        pair<ll,ll> *lazy=new pair<ll,ll>[4*n]();
        while(q--) {
            int option;
            cin>>option;
            if(option==2) {
                int left,right;
                cin>>left>>right;
                cout<<query(tree,lazy,0,n-1,1,left-1,right-1)<<endl;
            }
            else if(option==1) {
                int left,right,x;
                cin>>left>>right>>x;
                update(tree,lazy,0,n-1,1,left-1,right-1,1,x);
            }
            else {
                int left,right,x;
                cin>>left>>right>>x;
                update(tree,lazy,0,n-1,1,left-1,right-1,2,x);
            }
        }
    }
    return 0;
}
