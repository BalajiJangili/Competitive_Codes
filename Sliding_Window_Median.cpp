 // Author:J.Balaji
 
 #include<bits/stdc++.h>
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
//  const int N = 2e5 + 1;
 const int MOD = 1e9 + 7;
 const int inf = LLONG_MAX;
 const int minf = LLONG_MIN;
 using namespace std;
 
 // ----------------------------------------------------------------------
 
 bool isprimee(ll n)
 {
     if(n<=1)return false;
     else if(n<=3)return true;
     else if(n%2==0 || n%3==0)return false;
     for(ll i=5;i*i<=n;i+=6)
     {
         if(n%i==0 || n%(i+2)==0)return false;
     }
     return true;
 }
 
const int N = 1e6 + 5;  // Define N as per your requirement
vector<bool> Prime(N, true);
vector<int> p;
void sieve() {
    Prime[0] = Prime[1] = false;  // 0 and 1 are not prime
    for (int i = 2; i * i < N; i++) {
        if (Prime[i]) {
            for (int j = i * i; j < N; j += i) {
                Prime[j] = false;  // Mark multiples as non-prime
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (Prime[i]) p.push_back(i);
    }
}
 
 // For 64-bit integers
ll nearestpowerof2(ll n) {
    if (n == 0) return 1; n |= (n >> 1); n |= (n >> 2); n |= (n >> 4); n |= (n >> 8); n |= (n >> 16); n |= (n >> 32);  return (n + 1) >> 1;
}

 
 int powe(int a, int b, int m){ if(b == 0) return 1; int ans = powe(a, b/2, m); ans = (ans * ans)%m; if(b&1) return (ans * a)%m; return ans;}
 int minv(int a, int m){ a %= m; return powe(a, m - 2, m);}
 int madd(int a, int b, int m){a %= m; b %= m; return (((a + b)%m) + m)%m;}
 int msub(int a, int b, int m){a %= m; b %= m; return (((a - b)%m) + m)%m;}
 int mmul(int a, int b, int m){a %= m; b %= m; return (((a * b)%m) + m)%m;}
 int mdiv(int a, int b, int m){a %= m; b %= m; return (mmul(a, minv(b, m), m) + m) %m;}
 int mnCr(int n, int r, int m, vector<int>& fact){return mmul(fact[n], minv(mmul(fact[r], fact[n - r], m), m), m);}
 
 // ----------------------------------------------------------------------
 
 void solved(){
      int n;
      cin>>n;
      if(n<4){
        if(n==1){
            cout<<1;
        }
        else
        cout<<"NO SOLUTION";
      }
      else{
        int i;
         i=2;
         while(i<=n){
            cout<<i<<" ";
            i+=2;
         }
         i=1;
         while(i<=n){
            cout<<i<<" ";
            i+=2;
         }
      }
      
 }
 signed main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t = 1;
    //  cin >> t;
     while (t--)
     {
         solved();
     }
 }