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

int n,m;
int dis[100][100];

void solve(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof(dis));
    while(m--){
        int u,v,y;
        cin>>u>>v>>y;
        u--;
        v--;
        dis[u][v]=dis[v][u]=y;
    }
    fr(i,n) dis[i][i]=0;
    fr(k,n)fr(i,n)fr(j,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    if(dis[0][n-1]>1000000000000000000LL){
        cout<<"inf";
        return;
    }
    int ord[100];
    iota(ord,ord+n,0);
    sort(ord+1,ord+n,[](int a,int b){
        return dis[0][a]<dis[0][b];
    });
    string s(n,'0');
    vector<pair<string,int>> ans;
    fr(i,n-1){
        int u=ord[i],v=ord[i+1];
        s[u]='1';
        ans.emplace_back(s,dis[0][v]-dis[0][u]);
        if(v==n-1) break;
    }
    cout<<dis[0][n-1]<<" "<<sz(ans)<<'\n';
    for(auto [mask,t]:ans) cout<<mask<<" "<<t<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}