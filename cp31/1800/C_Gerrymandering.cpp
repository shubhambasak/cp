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

	vector<string> a(2);
	for (auto &row : a) cin >> row;

	map<pair<int, int>, int> dp;

	auto winner = [&](pair<int, int> A, pair<int, int> B, pair<int, int> C) -> int {
		return ((a[A.first][A.second] == 'A') + (a[B.first][B.second] == 'A') + (a[C.first][C.second] == 'A')) >= 2;
	};

    
    function<int(int, int)> f = [&](int i, int j) -> int {
	    if (i >= n || j >= n) return 0;
	    if (dp.count({i, j})) return dp[{i, j}];

	    int option1 = (max(i + 2, j + 2) < n) ? winner({0, i}, {0, i + 1}, {0, i + 2}) +
	    winner({1, j}, {1, j + 1}, {1, j + 2}) + f(i + 3, j + 3) : 0;
    
        int option2 = ((i == j || i + 1 == j) && i + 1 < n && j < n) ? winner({0, i}, {1, j}, {0, i + 1}) + f(i + 2, j + 1): 0;
        int option3 = ((i == j || i == j + 1) && j + 1 < n && i < n) ? winner({0, i}, {1, j}, {1, j + 1}) + f(i + 1, j + 2): 0;

        return dp[{i, j}] = max({option1, option2, option3});
	};

	cout << f(0, 0) << '\n';
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
