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

int n,m,pos,c1,c2;
vvi adj;
vi col;

void dfs(int x){
    if(x<n) col[x]==1?c1++:c2++;
    int nc=col[x]==1?2:1;
    for(auto &y:adj[x]){
        if(col[y]){
            if(col[y]!=nc) pos=0;
            continue;
        }
        col[y]=nc;
        dfs(y);
    }
}

void solve(){
    cin>>n>>m;
    adj=vvi(n+m);
    int fake=n;
    fr(j,m){
        int u,v; string c;
        cin>>u>>v>>c;
        --u,--v;
        if(c=="imposter"){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }else{
            adj[u].push_back(fake);
            adj[fake].push_back(u);
            adj[v].push_back(fake);
            adj[fake].push_back(v);
            fake++;
        }
    }
    col=vi(n+m);
    int ans=0;
    pos=1;
    fr(i,n) if(!col[i]){
        c1=c2=0;
        col[i]=1;
        dfs(i);
        ans+=max(c1,c2);
    }
    if(!pos) ans=-1;
    cout<<ans<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}