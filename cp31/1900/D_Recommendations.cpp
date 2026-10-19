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

	vector<pair<int, int>> l_order(n);
	fr(i,n) cin >> l_order[i].first >> l_order[i].second;
    map<pair<int, int>, int> index;
	fr(i,n) index[l_order[i]] = i;
    sort(l_order.begin(), l_order.end(), [](const pair<int, int> &A, const pair<int, int> &B) {
		if (A.first != B.first) return A.first < B.first;
		return A.second > B.second;
	});
    vector<pair<int, int>> r_order = l_order;
	sort(r_order.begin(), r_order.end(), [](const pair<int, int> &A, const pair<int, int> &B) {
		if (A.second != B.second) return A.second > B.second;
		return A.first < B.first;
	});
    vi ans_l(n, 0), ans_r(n, 0);

	set<int> l_set, r_set;  
    fr(i,n) {
		int l = l_order[i].first;
		int r = l_order[i].second;
        auto it = r_set.lower_bound(r);
		if (it != r_set.end()) ans_l[index[{l, r}]] = *it - r;  
        r_set.insert(r);
	}
    fr(i,n){
		int l = r_order[i].first;
		int r = r_order[i].second;
        auto it = l_set.upper_bound(l);
		if (it != l_set.begin()) {
			--it;
			ans_r[index[{l, r}]] = l - *it; 
		}
		l_set.insert(l);
    }
    fr(i,n) cout << ans_l[i] + ans_r[i] << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
