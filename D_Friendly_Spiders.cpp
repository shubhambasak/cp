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
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

const int MAXA = 300000;

vector<int> spf(MAXA + 1);

void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}


vector<int> factorize(int x) {
    vi primes;
    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);
        while (x % p == 0) x /= p;
    }
    return primes;
}

void solve() {
    int n;
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 1 << "\n" << s << "\n";
        return;
    }

    vector<vi> fact(n + 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = factorize(a[i]);
    }

    vector<vi> spiders_by_prime(MAXA + 1);
    for (int i = 1; i <= n; i++) {
        for (int p : fact[i]) {
            spiders_by_prime[p].push_back(i);
        }
    }

    vi dist(n + 1, -1), parent(n + 1, -1);
    vector<bool> prime_used(MAXA + 1, false);

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int p : fact[u]) {
            if (prime_used[p]) continue;
            prime_used[p] = true;

            for (int v : spiders_by_prime[p]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
    }

    if (dist[t] == -1) {
        cout << -1 << "\n";
        return;
    }

    vi path;
    for (int v = t; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    fr(i,(int)path.size()) cout << path[i] << " \n"[i + 1 == path.size()];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(); 
    solve();

    return 0;
}