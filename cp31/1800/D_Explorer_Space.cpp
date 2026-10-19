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

void solve(){
	int n, m, k;
	cin >> n >> m >> k;

	vector<vi> right(n, vector<long long>(m - 1)); 
	vector<vi> down(n - 1, vector<long long>(m));

	fr(i,n) for (int j = 0; j < m - 1; j++) cin >> right[i][j];
	for (int i = 0; i < n - 1; i++) fr(j,m) cin >> down[i][j];

	if (k % 2) {
		fr(i,n) {
			fr(j,m) cout << -1 << ' ';
			cout << '\n';
		}
        return;
	}
	
    int half = k / 2;
	vector<vector<vi>> dp(n, vector<vi>(m,vi(half + 1, INF)));

	fr(i,n) fr(j,m) dp[i][j][0] = 0; 

	for(int step = 1; step <= half; step++) {
		fr(i,n){
			fr(j,m){
                if (i > 0) {
                    dp[i][j][step] = min(dp[i][j][step], dp[i - 1][j][step - 1] + down[i - 1][j]);
				}
			    if (i < n - 1) {
                    dp[i][j][step] = min(dp[i][j][step], dp[i + 1][j][step - 1] + down[i][j]);
				}
				if (j > 0) {
                    dp[i][j][step] = min(dp[i][j][step], dp[i][j - 1][step - 1] + right[i][j - 1]);
				}
				if (j < m - 1) {
                    dp[i][j][step] = min(dp[i][j][step], dp[i][j + 1][step - 1] + right[i][j]);
				}
			}
		}
	}

	fr(i,n){
        fr(j,m) cout << 2 * dp[i][j][half] << ' ';
		cout << '\n';
	}
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
