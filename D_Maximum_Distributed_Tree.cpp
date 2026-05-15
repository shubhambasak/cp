#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x,y)  bitset<y>(x)

using namespace std;

const int MOD = 1000000007;

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

template<typename typC,typename typD>
istream &operator>>(istream &cin,pair<typC,typD> &a) {
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a) {
    for (auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a) {
    return cout<<a.first<<' '<<a.second;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) {
    for (auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a) {
    int n=a.size();
    if (!n) return cout;
    cout<<a[0];
    for (int i=1; i<n; i++) cout<<' '<<a[i];
    return cout;
}

vvi g;
vi weights;

int dfs(int u, int p, int n) {
    int sz = 1;

    for (int v : g[u]) {
        if (v != p) {
            int s = dfs(v, u, n);

            weights.push_back((s * (n - s)));

            sz += s;
        }
    }

    return sz;
}

void solve() {

    int n;
    cin >> n;

    g.assign(n + 1, {});

    fr(i, n - 1) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    weights.clear();

    dfs(1, -1, n);

    sort(all(weights));

    int m;
    cin >> m;

    vi f;

    while ((int)f.size() < n - 1 - m)
        f.push_back(1);

    fr(i, m) {
        int x;
        cin >> x;
        f.push_back(x);
    }

    sort(all(f));

    while ((int)f.size() > n - 1) {
        int x = f.back();
        f.pop_back();

        f.back() = (f.back() * x) % MOD;
    }

    int ans = 0;

    fr(i, n - 1) {
        ans = (ans + (weights[i] % MOD) * (f[i] % MOD)) % MOD;
    }

    cout << ans << "\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;

    while (T--)
        solve();

    return 0;
}