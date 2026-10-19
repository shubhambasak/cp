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

int n;
void solve(){
    vi b,p;
    vb isUsed;
    set<int> unused;
    cin>>n;
    b.assign(n/2,0);
    p.assign(n,0);
    isUsed.assign(n+1,false);
    fr(i,n/2){
        cin>>b[i];
        p[i*2+1]=b[i];
        isUsed[b[i]]=true;
    }
    for(int x=1;x<=n;x++) if(!isUsed[x]) unused.insert(x);
    if(sz(unused)!=n/2){
        cout<<"-1\n";
        return;
    }
    for(int i=n/2-1;i>=0;i--){
        auto k=unused.upper_bound(p[2*i+1]);
        if(k==unused.begin()){
            cout<<"-1\n";
            return;
        }
        --k;
        if(*k<p[2*i+1]){
            p[2*i]=*k;
            unused.erase(k);
        }
        else{
            cout<<"-1\n";
            return;
        }
    }
    for(int v:p) cout<<v<<' ';
    nl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}