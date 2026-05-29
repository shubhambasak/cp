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
    for (auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a){
    return cout<<a.first<<' '<<a.second;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a){
    for (auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a){
    int n=a.size();
    if (!n) return cout;
    cout<<a[0];
    for (int i=1; i<n; i++) cout<<' '<<a[i];
    return cout;
}

// ===================================END Of the input module ==========================================

int n;
vb vis;
vvi adj;
void dfs(int i,int &cycle,int &len){
    vis[i]=true,len++;
    if(sz(adj[i])<2) cycle=false;
    for(auto j:adj[i]){
        if(vis[j]) continue;
        dfs(j,cycle,len);
    }
}

void solve(){
    cin>>n;
    adj.assign(n,{});
    vis.assign(n,false);
    fr(i,n){
        int x;
        cin>>x, --x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    int b=0;
    int c=0;
    fr(i,n){
        if(vis[i]) continue;
        int cycle=1;
        int len=0;
        dfs(i,cycle,len);
        if(cycle && len>2) c++;
        else b++;
    }
    if(b) cout<<c+1<<" "<<c+b<<endl;
    else cout<<c<<" "<<c<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}