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

// ================================== take ip/op like vector,pairs directly!==================================

template<typename typC,typename typD>
istream &operator>>(istream &cin,pair<typC,typD> &a){
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a){
    for(auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a){
    return cout<<a.first<<' '<<a.second;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a){
    for(auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a){
    int n=a.size();
    if(!n) return cout;
    cout<<a[0];
    for(int i=1;i<n;i++) cout<<' '<<a[i];
    return cout;
}

// ===================================END Of the input module ==========================================

void solve(){
    int n;
    cin>>n;
    vector<string> g(n),w(n);
    fr(i,n) cin>>g[i]>>w[i];
    vvi adj(n,vi(n,0));
    fr(i,n) fr(j,n) if(i!=j && (g[i]==g[j] || w[i]==w[j])) adj[i][j]=1;
    int N=(1<<n);
    vvi dp(N,vi(n,0));
    for(int mask=1;mask<N;mask++){
        fr(last,n){
            if(!(mask&(1<<last)))
                continue;
            if(mask==(1<<last)){
                dp[mask][last]=1;
                continue;
            }
            int prev_mask=mask^(1<<last);
            fr(prev,n){
                if((prev_mask&(1<<prev)) &&
                   dp[prev_mask][prev] &&
                   adj[prev][last]){
                    dp[mask][last]=1;
                    break;
                }
            }
        }
    }
    int best=0;
    for(int mask=0;mask<N;mask++){
        fr(last,n) if(dp[mask][last]) best=max(best,(int)__builtin_popcount(mask));
    }
    cout<<n-best<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}