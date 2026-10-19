// Author:J.Balaji

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// ----------------------------------------------------------------------

class SGTree{
    vector<ll>seg,lazy;

public:
    SGTree(int n){
        seg.resize(4*n,0);
        lazy.resize(4*n,0);
    }

    void build(int ind,vector<ll>&v,int low,int high){
        if(low==high){
            seg[ind]=v[low];
            return;
        }

        int mid=(low+high)>>1;

        build(2*ind+1,v,low,mid);
        build(2*ind+2,v,mid+1,high);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    void propagate(int ind,int low,int high){
        if(lazy[ind]==0)return;

        seg[ind]+=(high-low+1)*lazy[ind];

        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }

        lazy[ind]=0;
    }

    void update(int ind,int low,int high,int l,int r,ll val){
        propagate(ind,low,high);

        if(high<l||r<low)return;

        if(l<=low&&high<=r){
            seg[ind]+=(high-low+1)*val;

            if(low!=high){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }

            return;
        }

        int mid=(low+high)>>1;

        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    ll query(int ind,int low,int high,int i){
        propagate(ind,low,high);
        if(low==high)return seg[ind];
        int mid=(low+high)>>1;
        if(i<=mid){
            return query(2*ind+1,low,mid,i);
        }
        return query(2*ind+2,mid+1,high,i);
    }
};

// ----------------------------------------------------------------------

void solved(){
    int n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    SGTree sg(n);
    sg.build(0,v,0,n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            ll val;
            cin>>l>>r>>val;
            l--,r--;
            sg.update(0,0,n-1,l,r,val);
        }
        else{
            int pos;
            cin>>pos;
            pos--;
            cout<<sg.query(0,0,n-1,pos)<<'\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;

    while(t--){
        solved();
    }

    return 0;
}