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

int MOD=998244353;

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

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

int add(int a,int b,int m=MOD)
{
    return ((a%m)+(b%m)+m)%m;
}

int sub(int a,int b,int m=MOD)
{
    return ((a%m)-(b%m)+m)%m;
}

int mul(int a,int b,int m=MOD)
{
    return ((a%m)*(b%m))%m;
}

int modexp(int a,int e,int m=MOD){
    a%=m;
    int r=1;
    while(e){
        if(e&1) r=mul(r,a,m);
        a=mul(a,a,m);
        e>>=1;
    }
    return r;
}

int inv(int a,int m=MOD)
{
    return modexp(a,m-2,m);
}

void solve(){
    int n;
    cin>>n;
    int T=n/3;
    int K=n/6;
    int ans=1;
    rep(i,1,K){
        ans=mul(ans,T-i+1);
        ans=mul(ans,inv(i));
    }
    vi e(3);
    fr(i,n){
        int w;
        cin>>w;
        e[i%3]=w;
        if(i%3==2){
            srt(e);
            int m=1;
            if(e[0]==e[1]) ++m;
            if(e[0]==e[2]) ++m;
            ans=mul(ans,m);
        }
    }
    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}