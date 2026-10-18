
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define int ll

class SGTree {
    vector<tuple<int,int,int>> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n);
    }
    void build(const string &s, int l, int r, int ind) {
        if (l == r) {
            tuple<int,int,int>tp;
            get<0>(tp) = (s[l] == '(');
            get<1>(tp) = (s[l] == ')');
            get<2>(tp) = 0;
            seg[ind]=tp;  
            return;
        }
        int m = (l + r) / 2;
        build(s, l, m, 2 * ind + 1);
        build(s, m + 1, r, 2 * ind + 2);
        int lo=get<0>(seg[2*ind+1]);
        int lo2=get<0>(seg[2*ind+2]);
        int rc=get<1>(seg[2*ind+2]);
        int rc1=get<1>(seg[2*ind+1]);
        int mf=min(lo,rc);
        int lf=get<2>(seg[2*ind+1]);
        int rf=get<2>(seg[2*ind+2]);
        int cf=lf+rf+mf;
        int cl=lo+lo2-mf;
        int cc=rc+rc1-mf;
        get<0>(seg[ind])=cl;
        get<1>(seg[ind])=cc;
        get<2>(seg[ind])=cf;        
    }
    tuple<int,int,int> query(int l, int r, int lo, int ri, int ind) {
        if (r < lo || ri < l) {
            tuple<int,int,int>tp;
            get<0>(tp) = 0;
            get<1>(tp) = 0;
            get<2>(tp) = 0;
            return tp;
        }
        if (lo <= l && r <= ri) {
            return seg[ind];
        }
        int m = (l + r) / 2;
        tuple<int,int,int> left = query(l, m, lo, ri, 2 * ind + 1);
        tuple<int,int,int> right = query(m + 1, r, lo, ri, 2 * ind + 2);
        int lo1=get<0>(left);
        int lo2=get<0>(right);
        int rc=get<1>(right);
        int rc1=get<1>(left);
        int mf=min(lo1,rc);
        int lf=get<2>(left);
        int rf=get<2>(right);
        int cf=lf+rf+mf;
        int cl=lo1+lo2-mf;
        int cc=rc+rc1-mf;
        tuple<int,int,int>tp;
        get<0>(tp)=cl;
        get<1>(tp)=cc;
        get<2>(tp)=cf;
        return tp; 
        
    }
    // void update(int i, int val, int low, int high, int ind,int orr) {
    //     if (low == high) {
    //         seg[ind] = val;
    //         return;
    //     }
    //     int m = (low + high) / 2;
    //     if (i <= m) {
    //         update(i, val, low, m, 2 * ind + 1,!orr);
    //     } else {
    //         update(i, val, m + 1, high, 2 * ind + 2,!orr);
    //     }
    //     if(orr){
    //         seg[ind]=seg[2*ind+1]|seg[2*ind+2];
    //     }
    //     else{
    //         seg[ind]=seg[2*ind+1]^seg[2*ind+2];
    //     }
    // }
    // int root(){
    //     return seg[0];
    // }
};
void solved() {
    string s;
    cin>>s;
    int n=s.size();
    int q;
    cin>>q;
    SGTree sg(n);
    sg.build(s,0,n-1,0);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        tuple<int,int,int>tp;
        tp=sg.query(0,n-1,l,r,0);
        int fu=2*get<2>(tp);
        cout<<fu<<'\n';
    }

    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solved();
    return 0;
}
