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


const int INF = numeric_limits<int>::min(); 
struct SegmentTree {
	int n;
	vi tree;
    SegmentTree(const vi& arr) {
		n = arr.size();
		tree.resize(4 * n);
		build(arr, 0, 0, n - 1);
	}

	void build(const vi& arr, int v, int tl, int tr) {
		if (tl == tr) tree[v] = arr[tl]; 
		else {
			int tm = (tl + tr) / 2;
			build(arr, 2 * v + 1, tl, tm);
			build(arr, 2 * v + 2, tm + 1, tr);
			tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);  
		}
    }

	int query(int l, int r) {
		if (l > r) return INF;  
        return query_recursive(0, 0, n - 1, l, r);
	}

	int query_recursive(int v, int tl, int tr, int l, int r) {
		if (l > r) return INF;
		if (l == tl && r == tr) return tree[v];  
        int tm = (tl + tr) / 2;
		return max(
			query_recursive(2 * v + 1, tl, tm, l, min(r, tm)),
			query_recursive(2 * v + 2, tm + 1, tr, max(l, tm + 1), r)
		);
	}
};

string solve() {
	int n;
	cin >> n;
	vi a(n);
	fr(i,n) cin >> a[i];

	vi x(n, -1), y(n, n);  
    stack<int> s_pge, s_nge;
    fr(i,n){
		while (!s_pge.empty() && a[s_pge.top()] <= a[i]) s_pge.pop();
		if (!s_pge.empty()) x[i] = s_pge.top();
		s_pge.push(i);
	}
    for (int i = n - 1; i >= 0; --i) {
		while (!s_nge.empty() && a[s_nge.top()] < a[i]) s_nge.pop();
		if (!s_nge.empty()) y[i] = s_nge.top();
		s_nge.push(i);
	}
    vi ps(n + 1, 0), ss(n + 1, 0);
	fr(i,n) ps[i + 1] = ps[i] + a[i];
	for (int i = n - 1; i >= 0; --i) ss[i] = ss[i + 1] + a[i];
    
    SegmentTree ps_tree(ps);
	SegmentTree ss_tree(ss);
    fr(k,n){
		int l = x[k] + 1;
        int r = y[k] - 1;  
        int max_suffix_val = ss_tree.query(l, k);
		if (max_suffix_val > a[k] + ss[k + 1]) return "NO";
        int max_prefix_val = ps_tree.query(k + 1, r + 1);
		if (max_prefix_val > a[k] + ps[k]) return "NO";
	}
    return "YES";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << '\n';
	return 0;
}