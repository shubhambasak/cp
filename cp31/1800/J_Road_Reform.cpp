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


vi parent;
vi sz;

void make_set(int v) {
	parent[v] = v;  
	sz[v] = 1;     
}

int find_set(int v) {
	if (v == parent[v]) return v;              
	return parent[v] = find_set(parent[v]);     
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a, b);  
	    	parent[b] = a;
			sz[a] += sz[b];
	}
}

struct Edge {
	int u, v, w;
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	parent.resize(n + 1);
	sz.resize(n + 1);
	for (int i = 1; i <= n; i++) make_set(i);  

	vector<Edge> edges(m);
	fr(i,m) cin >> edges[i].u >> edges[i].v >> edges[i].w;  

	sort(edges.begin(), edges.end(), [&](const Edge& a, const Edge& b) { return a.w < b.w; }); 

	int ans = 0;
	const int INF = 9e18; 

	for (const auto& e : edges) {
		if (e.w < k && find_set(e.u) != find_set(e.v)) union_sets(e.u, e.v);
	}

	bool taken_edge_above_k = false; 
	int min_cost = INF;   
	for (const auto& e : edges) {
		min_cost = min(min_cost, llabs(k - e.w));  

	    if (e.w >= k && find_set(e.u) != find_set(e.v)) {
		    ans += (e.w - k);    
		    union_sets(e.u, e.v);  
		    taken_edge_above_k = true;
	    }
	}
    if (!taken_edge_above_k) ans = min_cost;
	cout << ans << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

