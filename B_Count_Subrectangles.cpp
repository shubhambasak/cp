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
#define srt(v) sort(all(v)
#define rsrt(v) sort(rall(v))
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))
#define unq(v) v.resize(distance(v.begin(),unique(all(v))))
#define bin(x,y) bitset<y>(x)

using namespace std;

const int MOD=1e9+7;

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
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n),b(m);
    cin>>a;
    cin>>b;
    vi fa(n+1,0),fb(m+1,0);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cnt++;
            fa[cnt]++;
        }
        else cnt=0;
    }
    cnt=0;
    for(int i=0;i<m;i++){
        if(b[i]==1){
            cnt++;
            fb[cnt]++;
        }
        else cnt=0;
    }
    for(int i=n-1;i>0;i--) fa[i]+=fa[i+1];
    for(int i=m-1;i>0;i--) fb[i]+=fb[i+1];
    int ans=0;
    for(int i=1;i*i<=k;i++){
        if(k%i!=0)
            continue;
        int j=k/i;
        if(i<=n && j<=m) ans+=fa[i]*fb[j];
        if(i!=j && j<=n && i<=m) ans+=fa[j]*fb[i];
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
