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
istream &operator>>(istream &cin,pair<typC,typD> &a)
{
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a)
{
    for (auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a)
{
    return cout<<a.first<<' '<<a.second;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
    for (auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a)
{
    int n=a.size();

    if (!n) return cout;

    cout<<a[0];

    for (int i=1; i<n; i++)
        cout<<' '<<a[i];

    return cout;
}

// ===================================END Of the input module ==========================================

const int MAXA=1000000;
vector<uint> mask(MAXA+1);

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    rep(i,1,n) cin>>a[i];
    vector<uint> pref(n+1,0);

    rep(i,1,n) pref[i]=pref[i-1]^mask[a[i]];

    while(q--){
        int l,r;
        cin>>l>>r;
        uint x=pref[r]^pref[l-1];
        cout<<(x==0?"YES":"NO") << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    rep(i,1,MAXA) mask[i]=rng();
    int T = 1;
    cin >> T;
    while (T--) solve();
    
    return 0;
}