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

int MOD=998244353;

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

int modpow(int a,int b){
    int r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

void solve(){
    int n;
    cin>>n;
    int N=2*n;
    vi a(N);
    cin>>a;
    unordered_map<int,int> freq;
    for(int x:a) freq[x]++;
    auto is_prime=[&](int x){
        if(x<2) return false;
        for(int i=2;i*i<=x;i++)
            if(x%i==0) return false;
        return true;
    };
    vi primes,nonprimes;
    for(auto &[val,cnt]:freq){
        if(is_prime(val)) primes.push_back(cnt);
        else nonprimes.push_back(cnt);
    }
    if(sz(primes)<n){
        cout<<0<<"\n";
        return;
    }
    vi fact(N+1),invfact(N+1);
    fact[0]=1;
    for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[N]=modpow(fact[N],MOD-2);
    for(int i=N;i>0;i--) invfact[i-1]=invfact[i]*i%MOD;
    int t=sz(primes);
    vector<vi> dp(t+1,vi(n+1,0));
    dp[t][0]=1;
    for(int i=t-1;i>=0;i--){
        for(int j=0;j<=n;j++){
            dp[i][j]=invfact[primes[i]]*dp[i+1][j]%MOD;
            if(j>0)
                modadd(dp[i][j],invfact[primes[i]-1]*dp[i+1][j-1]%MOD);
        }
    }
    int common=fact[n];
    for(int c:nonprimes)
        common=common*invfact[c]%MOD;
    int ans=common*dp[0][n]%MOD;
    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}