
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define int ll

class SGTree {
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n);
    }
    void build(vector<int>& v, int l, int r, int ind,int orr) {
        if (l == r) {
            seg[ind] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(v, l, m, 2 * ind + 1,!orr);
        build(v, m + 1, r, 2 * ind + 2,!orr);
        if(orr)
        seg[ind] = seg[2 * ind + 1]|seg[2 * ind + 2];
        else{
            seg[ind] = seg[2 * ind + 1]^seg[2 * ind + 2];
        }
    }
    int query(int l, int r, int lo, int ri, int ind) {
        if (r < lo || ri < l) {
            return 0;
        }
        if (lo <= l && r <= ri) {
            return seg[ind];
        }
        int m = (l + r) / 2;
        int left = query(l, m, lo, ri, 2 * ind + 1);
        int right = query(m + 1, r, lo, ri, 2 * ind + 2);
        return left+right;
    }
    void update(int i, int val, int low, int high, int ind,int orr) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int m = (low + high) / 2;
        if (i <= m) {
            update(i, val, low, m, 2 * ind + 1,!orr);
        } else {
            update(i, val, m + 1, high, 2 * ind + 2,!orr);
        }
        if(orr){
            seg[ind]=seg[2*ind+1]|seg[2*ind+2];
        }
        else{
            seg[ind]=seg[2*ind+1]^seg[2*ind+2];
        }
    }
    int root(){
        return seg[0];
    }
};
void solved() {
    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solved();
    return 0;
}
