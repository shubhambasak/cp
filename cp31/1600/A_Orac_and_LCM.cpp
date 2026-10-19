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

const int maxn=100005;
int n;
int a[maxn];
int pre[maxn],suf[maxn];

int gcd(int x,int y){
    if(y==0) return x;
    else return gcd(y,x%y);
}

int ga,ans;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    pre[1]=a[1];
    suf[n]=a[n];
    rep(i,2,n) pre[i]=gcd(pre[i-1],a[i]);
    for(int i=n-1;i>=1;i--) suf[i]=gcd(suf[i+1],a[i]);
    fr(i,n){
        if(i==0) ans=suf[2];
        else if(i==n-1) ans=ans*pre[n-1]/gcd(pre[n-1],ans);
        else ans=ans*gcd(pre[i],suf[i+2])/gcd(gcd(pre[i],suf[i+2]),ans);
    }
    cout<<ans<<'\n';
    return 0;
}