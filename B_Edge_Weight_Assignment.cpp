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

vvi g;
vi depth;
int n;

void dfs(int v, int p, int d) {
		depth[v] = d;
		for (int to : g[v]) {
				if (to == p) continue; 
				dfs(to, v, d + 1);
		}
}

void solve() {
	cin >> n;
	g.assign(n + 1, {});
	depth.assign(n + 1, 0);

	fr(i,n-1) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int root = 1;
	for (int i = 1; i <= n; i++) if (g[i].size() == 1) { root = i; break; }
    dfs(root, 0, 0); 
    int mn = 1; 
    for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1 && (depth[i] & 1)) {
            mn = 3; 
            break;
		}
	}

	int mx = n - 1;
    for (int v = 1; v <= n; v++) {
		int leafChild = 0;
		for (int to : g[v]) {
			if (g[to].size() == 1) leafChild++; 
        }
		if (leafChild > 1) mx -= (leafChild - 1); 
    }

	cout << mn << " " << mx << "\n";
}


int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}