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
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x,y) bitset<y>(x)

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

void dfs(int x,vvi &adj,vi &color,bool &pos){
    if(!pos)
        return;
    for(auto y:adj[x]){
        if(color[y]!=-1){
            if(color[y]==color[x]){
                pos=false;
                return;
            }
            continue;
        }
        color[y]=1-color[x];
        dfs(y,adj,color,pos);
    }
}

void solve(){
    int n;
    cin>>n;
    vvi doms_for_num(n);
    vector<pair<int,int>> domino(n);
    fr(i,n){
        cin>>domino[i];
        doms_for_num[domino[i].first-1].push_back(i);
        doms_for_num[domino[i].second-1].push_back(i);
    }
    bool pos=true;
    vvi adj(n);
    fr(v,n){
        if(sz(doms_for_num[v])>2){
            pos=false;
            break;
        }
        if(sz(doms_for_num[v])==2){
            int a=doms_for_num[v][0];
            int b=doms_for_num[v][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    if(!pos){
        cout<<"NO"<<endl;
        return;
    }
    vi color(n,-1);
    fr(i,n){
        if(!pos) break;
        if(color[i]!=-1)
            continue;

        color[i]=0;
        dfs(i,adj,color,pos);
    }
    cout<<(pos?"YES":"NO")<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}