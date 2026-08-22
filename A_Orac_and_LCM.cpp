#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
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

const int MOD=1e9+7;

void modadd(int &a,int b){
    a=((a%MOD)+(b%MOD))%MOD;
}

void modsub(int &a,int b){
    a=((a%MOD)-(b%MOD)+MOD)%MOD;
}

void modmul(int &a,int b){
    a=((a%MOD)*(b%MOD))%MOD;
}

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

void solve(){
    int n;
    cin>>n;
    const int NMAX=300000;
    vi primes;
    vb isPrime(NMAX+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=NMAX;i++){
        if(!isPrime[i])
            continue;
        primes.push_back(i);
        if(i*i<=NMAX) for(int j=i*i;j<=NMAX;j+=i) isPrime[j]=false;
    }
    map<int,int> cnt;
    map<int,vi> ex;
    fr(i,n){
        int x;
        cin>>x;
        for(auto p:primes){
            if(p*p>x)
                break;
            if(x%p) 
                continue;
            int e=0;
            while(x%p==0){
                x/=p;
                e++;
            }
            cnt[p]++;
            ex[p].push_back(e);
            srt(ex[p]);
            if(sz(ex[p])>2) ex[p].pop_back();
        }
        if(x>1){
            cnt[x]++;
            ex[x].push_back(1);
        }
    }
    int ans=1;
    for(auto [p,c]:cnt){
        if(c<n-1)
            continue;

        int e=0;

        if(c==n) e=ex[p][1];
        else e=ex[p][0];
        while(e--) ans*=p;
    }
    cout<<ans, nl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
                   