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

struct Edge{
    int to,w;
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<Edge>> adj(n+1);
    fr(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vi speed(n+1);
    rep(i,1,n) cin>>speed[i];
    const int INF=9e18;
    vector<vi> dist(n+1,vi(1001,INF));
    vector<vb> visited(n+1,vb(1001,false));
    set<pair<int,pair<int,int>>> pq;
    dist[1][speed[1]]=0;
    pq.insert({0,{1,speed[1]}});
    while(!pq.empty()){
        auto [time,state]=*pq.begin();
        pq.erase(pq.begin());
        auto [u,spd]=state;
        if(visited[u][spd])
            continue;
        visited[u][spd]=true;
        for(auto [v,w]:adj[u]){
            int new_time=time+w*spd;
            int new_spd=min(spd,speed[v]);
            if(new_time<dist[v][new_spd]){
                dist[v][new_spd]=new_time;
                pq.insert({new_time,{v,new_spd}});
            }
        }
    }
    int ans=mne(dist[n]);
    cout<<ans<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}