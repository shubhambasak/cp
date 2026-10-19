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

void solve() {
	int n, q;
	cin >> n >> q;
    vi v(n), SUM(n), XOR(n);
	fr(i,n) {
		cin >> v[i];
		SUM[i] = (i ? SUM[i - 1] : 0) + v[i];  
		XOR[i] = (i ? XOR[i - 1] : 0) ^ v[i]; 
	}

	int ans = SUM.back() - XOR.back(); 
    int l = 0, r = n - 1;   
    while (q--) {
		int L, R;
		cin >> L >> R;
		L--, R--; 
        if (ans == 0) { 
            cout << 1 << ' ' << 1 << '\n';
			return;
		}

		int p1 = L, p2 = L; 
        while (p1 <= R && p2 <= R) {
            int v1 = SUM[p2] - (p1 ? SUM[p1 - 1] : 0);
			int v2 = XOR[p2] ^ (p1 ? XOR[p1 - 1] : 0);
			int val = v1 - v2;
            if (val == ans && (p2 - p1) < (r - l)) r = p2,l = p1;
            if (val < ans) p2++;
			else p1++;
		}
		cout << l + 1 << ' ' << r + 1 << '\n'; 
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
}