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


void solve(){
    int n;
    cin >> n;
	vi a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	const int MAXV = 200;
	vvi pos(MAXV + 1);
	for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);  
    vvi pref(MAXV + 1, vector<int>(n + 1, 0));
	for (int v = 1; v <= MAXV; ++v)
		for (int i = 1; i <= n; ++i) pref[v][i] = pref[v][i - 1] + (a[i] == v);

	int ans = 1;  
    for (int v = 1; v <= MAXV; ++v) ans = max(ans, pref[v][n]);
    for (int x = 1; x <= MAXV; ++x) {
		int cnt = (int)pos[x].size();
		for (int k = 1; k * 2 <= cnt; ++k) {  
            int L = pos[x][k - 1] + 1;     
            int R = pos[x][cnt - k] - 1;  
            if (L > R) continue;
			
			int mid_max = 0;  
            for (int v = 1; v <= MAXV; ++v) {
                int cur = pref[v][R] - pref[v][L - 1];  
                if (cur > mid_max) mid_max = cur;
			}
			ans = max(ans, 2 * k + mid_max);
        }
	}
    cout << ans << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}