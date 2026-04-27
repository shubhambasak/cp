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

int n, k;
vector<vi> g;   
vi parent, subtree_size;   
int total_dist = 0;           
vi dist;              

int modpow(int a, int e) {
	int r = 1;
	while (e) {
		if (e & 1) r = r * a % MOD; 
		a = a * a % MOD;             
		e >>= 1;                      
	}
	return r;
}

int modFraction(int p,int q) {
    return p % MOD * modpow(q % MOD, MOD - 2) % MOD; 
}

void dfs(int u, int p, int d = 0) {
	parent[u] = p;                   
	subtree_size[u] = 1;
	total_dist += d;
	for (int v : g[u]){
		if (v != p) {
			dfs(v, u, d + 1);        
			subtree_size[u] += subtree_size[v]; 
		}
    }
}

void calculate_dist(int u, int p) {
	for (int v : g[u]){
		if (v != p) {
			dist[v] = dist[u] - subtree_size[v] + (n - subtree_size[v]);
			calculate_dist(v, u);
		}
    }
}

signed main() {
	cin >> n >> k;
	g.assign(n + 1, {});
	parent.resize(n + 1);
	subtree_size.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 0, u, v; i < n - 1; i++)
		cin >> u >> v, g[u].push_back(v), g[v].push_back(u);  

	if (k & 1) {                   
		cout << 1 << "\n";     
		return 0;
	}

	dfs(1, 0);
	dist[1] = total_dist;
	calculate_dist(1, 0);      
	int sumAll = accumulate(dist.begin() + 1, dist.end(), 0LL);
	int expectedDistance = modFraction(sumAll, n * (n - 1));
	cout << (expectedDistance + 1) % MOD << "\n";  
}
