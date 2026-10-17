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
#define srt(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x,y)  bitset<y>(x)
using namespace std;

int MOD=1e9+7;

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a){ return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a){ for(auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a){ return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a){ for(auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a){ int n=a.size(); if(!n) return cout; cout<<a[0]; for(int i=1;i<n;i++) cout<<' '<<a[i]; return cout; }

void solve(){
    int n,p;
    cin>>n>>p;
    vi a(n),b(n);
    vector<pair<int,int>> v(n);
    fr(i,n) cin>>a[i];
    fr(i,n) cin>>b[i];
    fr(i,n) v[i]={b[i],a[i]};
    sort(all(v));

    int minimum_cost=p;
    int already_shared=1;

    for(auto it:v){
        if(already_shared>=n) break;
        int sharing_cost=it.first;
        int can_be_shared=it.second;
        if(sharing_cost>=p) break;
        int take=min(can_be_shared,n-already_shared);
        minimum_cost+=take*sharing_cost;
        already_shared+=take;
    }

    minimum_cost+=(n-already_shared)*p;
    cout<<minimum_cost<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
