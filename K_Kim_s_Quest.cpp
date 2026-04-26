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
int MOD=998244353;  // Hardcoded, directly change from here for functions!



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

int n;
vi a, odd, even;             
int pairs[200005][2][2], dp[200005][2][2]; 

int solve(int i, int p1, int p2) {
	if (i <= 1) return 0;          
	int &res = dp[i][p1][p2];
	if (res != -1) return res;       
	res = solve(i - 1, p1, p2);    
    int p = a[i] & 1;                 
    if (p == p2) {  
        int need = (2 - p1 - p2) % 2;  
        res = (res + solve(i - 1, need, p1)) % MOD;
        res = (res + pairs[i - 1][need][p1]) % MOD;
	}
	return res;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	a.resize(n);
	odd.resize(n);
	even.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		odd[i] = (i ? odd[i - 1] : 0) + (a[i] & 1); 
        even[i] = i + 1 - odd[i];  
        if (i != 0) {
            for (int p1 = 0; p1 < 2; p1++)
			for (int p2 = 0; p2 < 2; p2++)
			pairs[i][p1][p2] = pairs[i - 1][p1][p2] + (((a[i] & 1) == p2) ? (p1 ? odd[i - 1] : even[i - 1]) : 0); 
        }
	}

	memset(dp, -1, sizeof(dp));
	int ans = 0;
    for (int p1 = 0; p1 < 2; p1++)
		for (int p2 = 0; p2 < 2; p2++)
		ans = (ans + solve(n - 1, p1, p2)) % MOD;

	cout << ans % MOD;
    return 0;
}