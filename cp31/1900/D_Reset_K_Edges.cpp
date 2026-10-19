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


const int N=200005;
vvi g(N);
int parent[N],depth[N];
vb used(N);
int n,k;

void dfs_mark(int u){
    used[u]=true;
    for(int v:g[u]){
        if(!used[v]) dfs_mark(v);
    }
}

bool check(int H,vi &order){
    fill(used.begin()+1,used.begin()+n+1,false);
    int cuts=0;
    for(int u:order){
        if(depth[u]<=H) break;
        if(used[u]) continue;
        int v=u;
        fr(i,H-1) v=parent[v];
        dfs_mark(v);
        cuts++;
        if(cuts>k) return false;
    }
    return true;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    parent[1]=0;
    for(int i=2;i<=n;i++){
        cin>>parent[i];
        g[parent[i]].push_back(i);
    }
    queue<int> q;
    q.push(1);
    depth[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            depth[v]=depth[u]+1;
            q.push(v);
        }
    }
    vi order(n);
    iota(all(order),1);
    sort(all(order),[&](int a,int b){
        return depth[a]>depth[b];
    });
    int low=1,high=n,ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,order)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}