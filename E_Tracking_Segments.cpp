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
istream &operator>>(istream &cin,pair<typC,typD> &a)
{
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a)
{
    for (auto &x:a) cin>>x;
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
    for (auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a)
{
    int n=a.size();

    if (!n) return cout;

    cout<<a[0];

    for (int i=1; i<n; i++)
        cout<<' '<<a[i];

    return cout;
}

// ===================================END Of the input module ==========================================

int n,m,q;
vector<pair<int,int>> seg;
vi qry;
bool check(int x){
    vi a(n,0);
    fr(i,x) a[qry[i]]=1;
    rep(i,1,n-1) a[i]+=a[i-1];
    for(auto &[l,r]:seg){
        int sum=a[r]-(l>0?a[l-1]:0);
        if(sum>(r-l+1)/2) return true;
    }
    return false;
}

void solve(){
    cin>>n>>m;
    seg.resize(m);
    for(auto &[l,r]:seg) cin>>l>>r, --l, --r;
    cin>>q;
    qry.resize(q);
    for(auto &x:qry) cin>>x, --x;
    int l=1;
    int r=q;
    int ans=INT_MAX;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=min(ans,mid), r=mid-1;
        else l=mid+1;
    }
    cout << (ans==INT_MAX?-1:ans) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}