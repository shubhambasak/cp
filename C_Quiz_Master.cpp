#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v.size())
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))
#define unq(v) v.resize(distance(v.begin(),unique(all(v))))
#define bin(x,y) bitset<y>(x)
using namespace std;
int MOD=1e9+7;

void modadd(int &a,int b){
    a=((a%MOD)+(b%MOD))%MOD;
}

void modsub(int &a,int b){
    a=((a%MOD)-(b%MOD)+MOD)%MOD;
}

void modmul(int &a,int b){
    a=((a%MOD)*(b%MOD))%MOD;
}

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
    int n,m;
    cin>>n>>m;
    vi a(n);
    cin>>a;
    srt(a);
    vi f(m+1,0);
    int cnt=0;
    int ans=LLONG_MAX;
    auto inc=[&](int x){
        if(x>m) return;
        if(f[x]==0) cnt++;
        f[x]++;
    };
    auto dec=[&](int x){
        if(x>m) return;
        f[x]--;
        if(f[x]==0) cnt--;
    };
    int r=-1;
    for(int l=0;l<n;l++){
        while(cnt<m && r+1<n){
            r++;
            int lim=sqrt(a[r]);
            for(int j=1;j<=lim;j++){
                if(a[r]%j)
                    continue;
                inc(j);
                int k=a[r]/j;
                if(k!=j) inc(k);
            }
        }
        if(cnt<m)
            break;
        ans=min(ans,a[r]-a[l]);
        int lim=sqrt(a[l]);
        for(int j=1;j<=lim;j++){
            if(a[l]%j)
                continue;
            dec(j);
            int k=a[l]/j;
            if(k!=j) dec(k);
        }
    }
    if(ans==LLONG_MAX) cout<<-1;
    else cout<<ans;
    nl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}

