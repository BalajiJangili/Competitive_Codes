
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class FenwickTree {
    int n;
    vector<ll> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int p, ll x) {
        while (p <= n) {
            bit[p] += x;
            p += p & -p;
        }
    }

    ll query(int p) {
        ll ans = 0;

        while (p > 0) {
            ans += bit[p];
            p -= p & -p;
        }

        return ans;
    }

    ll rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    void build(const vector<ll>& a) {
        for (int i = 1; i <= n; i++) {
            update(i, a[i]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    FenwickTree ft(n);
    ft.build(a);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int p;
            ll x;
            cin >> p >> x;
            ft.update(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.rangeQuery(l, r) << '\n';
        }
    }

    return 0;
}
