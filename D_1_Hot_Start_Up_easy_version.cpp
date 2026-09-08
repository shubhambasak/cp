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

const int INF=4e18;
void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vi cold(k+1),hot(k+1);
    for(int i=1;i<=k;i++) cin>>cold[i];
    for(int i=1;i<=k;i++) cin>>hot[i];
    vvi dp(n+1,vi(k+1,INF));
    dp[1][0]=cold[a[1]];
    for(int i=2;i<=n;i++){
        int x=a[i];
        for(int j=0;j<=k;j++){
            if(dp[i-1][j]==INF) continue;
            int cost1=(a[i]==a[i-1]?hot[x]:cold[x]);
            dp[i][j]=min(dp[i][j],dp[i-1][j]+cost1);
            int cost2=(j==x?hot[x]:cold[x]);
            dp[i][a[i-1]]=min(dp[i][a[i-1]],dp[i-1][j]+cost2);
        }
    }
    cout<<mne(dp[n])<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}