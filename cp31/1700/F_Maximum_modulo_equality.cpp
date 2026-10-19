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

template<typename T,T DefaultValue=T(),typename Operation=plus<T>> class segtree {
private:
    vector<T> v;
    int N=1;
    Operation op;

public:
    segtree(vector<T> &a){
        while(N<sz(a)) N*=2;
        v.assign(2*N-1,DefaultValue);
        build(0,0,N-1,a);
    }

    T build(int i,int L,int R,vector<T> &a){
        if(L==R) return v[i]=(L<sz(a)?a[L]:DefaultValue);
        int M=(L+R)/2;
        return v[i]=op(build(2*i+1,L,M,a),build(2*i+2,M+1,R,a));
    }

    T get(int x){
        return v[N-1+x];
    }

    void point_upd(int x,T val,int i,int L,int R){
        if(L==R){
            v[i]=val;
            return;
        }
        int M=(L+R)/2;
        if(x<=M) point_upd(x,val,2*i+1,L,M);
        else point_upd(x,val,2*i+2,M+1,R);
        v[i]=op(v[2*i+1],v[2*i+2]);
    }

    void point_upd(int x,T val){
        point_upd(x,val,0,0,N-1);
    }

    void point_op(int x,T val){
        point_upd(x,op(get(x),val));
    }

    T query(int ql,int qr,int i,int L,int R){
        if(R<ql || L>qr) return DefaultValue;
        if(ql<=L && R<=qr) return v[i];
        int M=(L+R)/2;
        return op(query(ql,qr,2*i+1,L,M),query(ql,qr,2*i+2,M+1,R));
    }

    T query(int ql,int qr){
        return query(ql,qr,0,0,N-1);
    }
};

struct GcdOperation{
    template<typename T> T operator()(const T &a,const T &b) const{return gcd(a,b);}
};

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n);
    cin>>a;
    vi d;
    rep(i,1,n-1) d.push_back(abs(a[i]-a[i-1]));
    segtree<int,0,GcdOperation> seg(d);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<seg.query(l,r-1)<<" ";
    }nl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}