
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SGTree {
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n);
    }
    void build(vector<int>& v, int l, int r, int ind) {
        if (l == r) {
            seg[ind] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(v, l, m, 2 * ind + 1);
        build(v, m + 1, r, 2 * ind + 2);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int l, int r, int lo, int ri, int ind) {
        if (r < lo || ri < l) {
            return INT_MAX;
        }
        if (lo <= l && r <= ri) {
            return seg[ind];
        }
        int m = (l + r) / 2;
        int left = query(l, m, lo, ri, 2 * ind + 1);
        int right = query(m + 1, r, lo, ri, 2 * ind + 2);
        return min(left, right);
    }
    void update(int i, int val, int low, int high, int ind) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int m = (low + high) / 2;
        if (i <= m) {
            update(i, val, low, m, 2 * ind + 1);
        } else {
            update(i, val, m + 1, high, 2 * ind + 2);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
void solved() {
    int n1, n2, q;
    cin >> n1 >> n2 >> q;
    vector<int> v(n1), a(n2);
    for (int i = 0; i < n1; i++) cin >> v[i];
    for (int i = 0; i < n2; i++) cin >> a[i];
    SGTree sg1(n1), sg2(n2);
    sg1.build(v, 0, n1 - 1, 0);
    sg2.build(a, 0, n2 - 1, 0);
    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int lo1, ri1, lo2, ri2;
            cin >> lo1 >> ri1 >> lo2 >> ri2;
            lo1--;
            ri1--;
            lo2--;
            ri2--;
            int left = sg1.query(0, n1 - 1, lo1, ri1, 0);
            int right = sg2.query(0, n2 - 1, lo2, ri2, 0);
        } else {
            int i1, val1, i2, val2;
            cin >> i1 >> val1 >> i2 >> val2;
            i1--;
            i2--;
            sg1.update(i1, val1, 0, n1 - 1, 0);
            sg2.update(i2, val2, 0, n2 - 1, 0);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solved();
    return 0;
}
