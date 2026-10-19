#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i,n) for(int i=0;i<(n);i++)
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
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

void modadd(int &a,int b){a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a,int b){a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a,int b){a=((a%MOD)*(b%MOD))%MOD;}

template<typename typC,typename typD>
istream &operator>>(istream &cin,pair<typC,typD> &a){return cin>>a.first>>a.second;}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a){
    for(auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a){return cout<<a.first<<' '<<a.second;}

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

int powm(int x,int n){
    x%=MOD;
    if(n==0) return 1;
    if(n==1) return x;
    int p=powm(x*x%MOD,n/2);
    if(n%2) return p*x%MOD;
    return p;
}

vvi adj;
vb vis;
int component_size;

void dfs(int x){
    vis[x]=1;
    component_size++;
    for(auto &i:adj[x]){
        if(!vis[i]) dfs(i);
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    adj.assign(n+1,{});
    fr(i,n-1){
        int u,v,x;
        cin>>u>>v>>x;
        if(x==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int ans=0;
    vis.assign(n+1,false);
    rep(i,1,n){
        if(!vis[i]){
            component_size=0;
            dfs(i);
            ans=(ans+powm(component_size,k))%MOD;
        }
    }
    ans=(powm(n,k)-ans+MOD)%MOD;
    cout<<ans<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}