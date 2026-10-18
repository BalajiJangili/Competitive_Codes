// Author:J.Balaji

#include<bits/stdc++.h>
using namespace std;
#define int long long

// ----------------------------------------------------------------------

  

// ----------------------------------------------------------------------

class SGTree{
    vector<int>seg,lazy;
public:
    SGTree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }
public:
    void build(int ind,vector<int>&v,int low,int high){
        if(low==high){
            seg[ind]=v[low];
            return;
        }
        int mid=(low+high) >> 1;
        build(2*ind+1,v,low,mid);
        build(2*ind+2,v,mid+1,high);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
public:
    void update(int ind,int low,int high,int l,int r, int val){
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }

        // low high l r or l r low high => no overlap 

        if(high<l or r< low){
            return;
        }

        // l low high r => complete overlap
        if(l<=low && high<=r){
             seg[ind]+=(high-low+1)*val;
             if(low!=high){
             lazy[2*ind+1]+=val;
             lazy[2*ind+2]+=val;
             }
             return;
        }

        int mid=(low+high) >> 1;
        update(2*ind+1,low , mid, l ,r , val);
        update(2*ind+2, mid+1, high, l, r, val);
        return;
    }
public:
    int query(int ind,int low, int high, int i){
         if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
         }
         if(low==high){
            return seg[ind];
         }
         int mid=(low+high) >> 1;
         if(i<=mid){
            return query(2*ind+1,low,mid,i);
         }
         return query(2*ind+2,mid+1,high,i);
    }
};


void solved(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    SGTree sg(n),lazy(n);
    sg.build(0,v,0,n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r,val;
            cin>>l>>r>>val;
            l--,r--;
            sg.update(0,0,n-1,l,r,val);

        }
        else{
            int pos;
            cin>>pos;
            pos--;
            cout<<sg.query(0,0,n-1,pos)<<endl;
        }
    }
    


    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solved();
    }
}