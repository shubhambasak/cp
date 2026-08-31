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

struct MaxOperation{
    template<typename T>
    T operator()(const T &a,const T &b) const{return max(a,b);}
};

template<typename T,typename Operation=MaxOperation>
class sparse_table{
    vector<vector<T>> v;
    int N,K;
    Operation op;
    int log2_floor(int x){return 31-__builtin_clz(x);}

public:
    sparse_table(vector<T> &a){
        N=a.size();
        K=log2_floor(N);
        v=vector<vector<T>>(K+1);
        v[0]=a;
        for(int i=1;i<=K;i++){
            v[i].resize(N-(1<<i)+1);
            for(int j=0;j+(1<<i)<=N;j++)
                v[i][j]=op(v[i-1][j],v[i-1][j+(1<<(i-1))]);
        }
    }
    T query(int L,int R){
        int i=log2_floor(R-L+1);
        return op(v[i][L],v[i][R-(1<<i)+1]);
    }
};

void solve(){
    int n,m; cin>>n>>m;
    vi a(m); cin>>a;
    sparse_table<int> st(a);
    int q; cin>>q;
    while(q--){
        int xs,ys,xf,yf,k;
        cin>>xs>>ys>>xf>>yf>>k;
        bool ans=abs(xs-xf)%k==0&&abs(ys-yf)%k==0;
        if(ys>yf) swap(ys,yf);
        int mx_allowed=(n/k)*k+(xs%k);
        if(mx_allowed>n) mx_allowed-=k;
        if(st.query(ys-1,yf-1)>=mx_allowed) ans=false;
        cout<<(ans?"YES\n":"NO\n");
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}