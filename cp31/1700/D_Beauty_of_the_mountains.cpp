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

void modadd(int &a,int b){a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a,int b){a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a,int b){a=((a%MOD)*(b%MOD))%MOD;}

// ================================== take ip/op like vector,pairs directly!==================================

template<typename typC,typename typD>
istream &operator>>(istream &cin,pair<typC,typD> &a)
{
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a)
{
    for(auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a)
{
    return cout<<a.first<<' '<<a.second;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
    for(auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a)
{
    int n=a.size();

    if(!n) return cout;

    cout<<a[0];

    for(int i=1;i<n;i++)
        cout<<' '<<a[i];

    return cout;
}

// ===================================END Of the input module ==========================================

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vvi a(n,vi(m));
    fr(i,n) fr(j,m) cin>>a[i][j];
    vvi type(n,vi(m));
    int D=0;
    fr(i,n){
        fr(j,m){
            char x;
            cin>>x;
            if(x=='0'){
                type[i][j]=0;
                D+=a[i][j];
            }
            else{
                type[i][j]=1;
                D-=a[i][j];
            }
        }
    }
    D=abs(D);
    if(D==0){
        cout<<"YES";
        nl;
        return;
    }
    int G=0;
    rep(i,0,n-k){
        int window=0;
        rep(x,i,i+k-1) fr(y,k) window+=(type[x][y]==0?1:-1);
        G=gcd(G,abs(window));
        rep(y,1,m-k){
            rep(x,i,i+k-1){
                window+=(type[x][y-1]==0?-1:1);
                window+=(type[x][y+k-1]==0?1:-1);
            }
            G=gcd(G,abs(window));
        }
    }
    if(G!=0 && D%G==0) cout<<"YES";
    else cout<<"NO";
    nl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}