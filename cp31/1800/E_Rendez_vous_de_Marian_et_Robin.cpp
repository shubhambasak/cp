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


const int INF = 1e18;

void solve() {
	int n, m, h;
	cin >> n >> m >> h;

	vector<vector<pair<int, int>>> g(n + 1);  
    vi horse(n + 1);              

	for (int i = 0, x; i < h; i++) {
        cin >> x;
		horse[x] = 1;
	}

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

    auto minimum_time = [&](int s) {
		vector<vector<int>> d(n + 1, vector<int>(2, INF)); 
		d[s][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
		pq.push({0, {s, 0}});

		while (!pq.empty()) {
			auto [du, st] = pq.top();
			pq.pop();
			auto [u, hb] = st;
			if (du != d[u][hb]) continue;  
            
            if (!hb && horse[u] && du < d[u][1]) {
				d[u][1] = du;
				pq.push({du, {u, 1}});	
        	}

			for (auto [v, w] : g[u]) {
				int nd = du + (hb ? w / 2 : w);
				if (nd < d[v][hb]) {
					d[v][hb] = nd;
					pq.push({nd, {v, hb}});
				}
    		}
		}
        vi res(n + 1);
		for (int i = 1; i <= n; i++) res[i] = min(d[i][0], d[i][1]);
		return res;
	};
    auto a = minimum_time(1), b = minimum_time(n);
    int ans = INF;
	for (int i = 1; i <= n; i++) ans = min(ans, (int)max(a[i], b[i]));  
	cout << (ans == INF ? -1 : ans) << '\n';
}


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
