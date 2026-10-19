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

// ================================== MOD FUNCTIONS ==================================

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

// ================================== INPUT / OUTPUT ==================================

template<typename typC,typename typD>
istream &operator>>(istream &cin,pair<typC,typD> &a) {
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a) {
    for (auto &x:a) cin>>x;
    return cin;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const pair<typC,typD> &a) {
    return cout<<a.first<<' '<<a.second;
}

template<typename typC,typename typD>
ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) {
    for (auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a) {
    int n=a.size();
    if (!n) return cout;

    cout<<a[0];

    for (int i=1; i<n; i++) {
        cout<<' '<<a[i];
    }

    return cout;
}

// ================================== END ==================================

const int LIM = 200000;
const int SZ = 2 * LIM + 1;

void solve(){

    int n,m,q;
    cin>>n>>m>>q;

    vi a(n),b(m);

    int A=0,B=0;

    cin>>a;
    cin>>b;

    fr(i,n) A+=a[i];
    fr(i,m) B+=b[i];

    vb hasU(SZ,false),hasV(SZ,false);

    fr(i,n){

        int u=A-a[i];

        if(abs(u)<=LIM){
            hasU[u+LIM]=true;
        }
    }

    fr(i,m){

        int v=B-b[i];

        if(abs(v)<=LIM){
            hasV[v+LIM]=true;
        }
    }

    auto check = [&](int d,int e,int x,bool &ok){

        if(abs(d)>LIM || abs(e)>LIM){
            return;
        }

        if(d*e!=x){
            return;
        }

        if(hasU[d+LIM] && hasV[e+LIM]){
            ok=true;
        }
    };

    while(q--){

        int x;
        cin>>x;

        int ax=abs(x);

        bool ok=false;

        for(int d=1; d*d<=ax && !ok; d++){

            if(ax%d){
                continue;
            }

            int e=ax/d;

            check(d,e,x,ok);
            check(e,d,x,ok);

            check(-d,-e,x,ok);
            check(-e,-d,x,ok);

            check(d,-e,x,ok);
            check(-d,e,x,ok);

            check(e,-d,x,ok);
            check(-e,d,x,ok);
        }

        cout<<(ok?"YES\n":"NO\n");
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}