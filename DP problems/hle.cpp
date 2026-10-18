 // Author:J.Balaji

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll          long long
#define pb          push_back
#define pob         pop_back
#define ye          cout << "YES\n"
#define no          cout << "NO\n"
#define fr(i,a,b)   for(int i=a;i<b;i++)
#define rfr(i,a,b)  for(int i=a;i>=b;i--)
#define trav(i,a)   for(auto &i : a)
#define frin        fr(i,0,n)
#define fi          first
#define se          second
#define vi          vector < int >
#define vli         vector <long long int >
#define vc          vector < char >
#define vpi         vector < pair < int, int >>
#define pi          pair < int, int >
#define mi          map < int, int >
#define mli         map < ll , ll >
#define mlc         map<char,int>
#define miv         map < int, vector < int >>
#define mae(v)      * max_element(v.begin(), v.end())
#define mie(v)      * min_element(v.begin(), v.end())
#define sv(v)       sort(v.begin(), v.end())
#define rsv(v)      sort(v.rbegin(), v.rend())
#define rv(v)       reverse(v.begin(), v.end())
#define vs(v)       accumulate(v.begin(), v.end(), 0)
#define vls(v)      accumulate(v.begin(),v.end(),(ll)0)
#define take(v,n)   for(int j=0;j<n;j++) cin>>v[j];
#define give(v,n)   for(int j=0;j<n;j++) cout<<v[j]<<' ';
#define lb          lower_bound
#define ub          upper_bound
#define bpc(x)      __builtin_popcountll(x) 
#define btz(x)      __builtin_ctzll(x)
const int MOD = 1e9 + 7;
const int inf = LLONG_MAX;
const int minf = LLONG_MIN;


// -------------------------------------------------------------------------------
// MOVED TYPEDEF HERE, AFTER 'pi' IS DEFINED
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
 
// -------------------------------------------------------------------------------
const int m=1e9+7;

void solved(){
    int n,k;
    cin>>n>>k;
    vi v(n);
    take(v,n);
    
    // Use the indexed_multiset you defined
    indexed_multiset s;
    fr(i,0,k){
        // Insert pairs {value, index} to handle duplicates
        s.insert({v[i], i});
    }

    // Find the median and access the value with ->fi
    cout << s.find_by_order((k - 1) / 2)->fi << " ";

    fr(i,k,n){
        // Erase the old pair
        s.erase({v[i-k], i-k});
        // Insert the new pair
        s.insert({v[i], i});
        // Find and print the new median
        cout << s.find_by_order((k - 1) / 2)->fi << " ";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solved();
    }
}