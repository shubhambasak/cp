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

void solve(){
    int n,a,b; cin>>n>>a>>b;
    --a,--b;
    vector<vector<pair<int,int>>> adj(n);
    fr(i,n-1){
        int x,y,w; cin>>x>>y>>w;
        --x,--y;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    auto dfs=[&](auto &&self,int x,int p,int xr,vi &v,int stop=-1)->void{
        if(x==stop) return;
        v[x]=xr;
        for(auto &[y,w]:adj[x]) if(y!=p) self(self,y,x,xr^w,v,stop);
    };
    vi v1(n,-1),v2(n,-1);
    dfs(dfs,a,-1,0,v1,b);
    dfs(dfs,b,-1,0,v2);
    bool ans=v1[b]==0;
    set<int> s;
    fr(i,n) if(i!=b&&v2[i]!=-1) s.insert(v2[i]);
    fr(i,n) if(v1[i]!=-1&&s.count(v1[i])) ans=true;
    cout<<(ans?"YES\n":"NO\n");
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}