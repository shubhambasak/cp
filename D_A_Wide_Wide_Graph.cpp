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


vector<int> bfs(int src, const vector<vector<int>> &g) {
	int n = g.size();
	vector<int> dist(n, -1);
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u])
		if (dist[v] == -1) { 
            dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	return dist;
}

int find_farthest(int start, const vector<vector<int>> &g) {
		auto dist = bfs(start, g);
		return int32_t(max_element(dist.begin(), dist.end()) - dist.begin());
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vi>g(n);
	for (int i = 0; i < n - 1; i++) {
	    int u, v;
		cin >> u >> v;
		--u; 
    	--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
    
    int A = find_farthest(0, g);
	int B = find_farthest(A, g);
	auto distA = bfs(A, g);
	auto distB = bfs(B, g);
    vector<vi> layer(n + 1); 
	for (int i = 0; i < n; i++) {
		int d = max(distA[i], distB[i]);
		layer[d].push_back(i);
	}

	vi ans(n + 1, 0);
	vi vis;
    for (int k = n; k >= 1; k--) {
        vis.insert(vis.end(), layer[k].begin(), layer[k].end());
        ans[k] = min(n, n - int32_t(vis.size()) + 1);
	}

	for (int k = 1; k <= n; k++) cout << ans[k] << " ";
	cout << "\n";
}

