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

const int N=2005;
vvi g(N);
int n,m;

void readGraph(){
    cin>>n>>m;
    rep(i,1,n) g[i].clear();
    fr(i,m){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

vi bfs(int u,int v){
    vi par(n+1,-1);
    queue<int> q;
    par[v]=u;
    q.push(v);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int nxt:g[cur]){
            if(cur==v && nxt==u) continue;
            if(par[nxt]!=-1) continue;
            par[nxt]=cur;
            q.push(nxt);
        }
    }
    return par;
}

vector<pair<int,int>> buildCycle(int u,int v,const vi &par,vb &in_cycle){
    vector<pair<int,int>> edges;
    int cur=u;
    while(cur!=v){
        in_cycle[cur]=true;
        edges.push_back({cur,par[cur]});
        cur=par[cur];
    }
    in_cycle[v]=true;
    edges.push_back({u,v});
    return edges;
}

vi getExtraNeighbors(int u,const vb &in_cycle){
    vi extra;
    for(int x:g[u]) if(!in_cycle[x]) extra.push_back(x);
    return extra;
}

bool findFishGraph(){
    rep(u,1,n){
        if(sz(g[u])<4) continue;
        for(int v:g[u]){
            vi par=bfs(u,v);
            if(par[u]==-1) continue;
            vb in_cycle(n+1,false);
            vector<pair<int,int>> edges=buildCycle(u,v,par,in_cycle);
            vi extra=getExtraNeighbors(u,in_cycle);
            if(sz(extra)<2) continue;
            edges.push_back({u,extra[0]});
            edges.push_back({u,extra[1]});
            cout<<"YES\n";
            cout<<sz(edges)<<'\n';
            for(auto &e:edges) cout<<e.first<<" "<<e.second<<'\n';
            return true;
        }
    }
    return false;
}

void solve(){
    readGraph();
    if(!findFishGraph()) cout<<"NO\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}