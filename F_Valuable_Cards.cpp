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

const int A=1e6+1;
bool used[A];
bool divs[A];

void solve(){
    int n,x;
    cin>>n>>x;
    vi a(n);
    cin>>a;
    vi vecDivs;
    for(int d=1;d*d<=x;d++){
        if(x%d==0){
            divs[d]=true;
            vecDivs.push_back(d);
            if(d*d<x){
                divs[x/d]=true;
                vecDivs.push_back(x/d);
            }
        }
    }
    int ans=1;
    used[1]=true;
    vi cur={1};
    fr(i,n){
        if(!divs[a[i]])
            continue;
        vi ncur;
        bool ok=true;
        for(auto d:cur){
            int prod=d*a[i];
            if(prod<=x && divs[prod] && !used[prod]){
                ncur.push_back(prod);
                used[prod]=true;
                if(prod==x) ok=false;
            }
        }
        for(auto d:ncur) cur.push_back(d);
        if(!ok){
            ans++;
            for(auto d:cur) used[d]=false;
            used[1]=true;
            used[a[i]]=true;
            cur={1,a[i]};
        }
    }

    for(auto d:vecDivs){
        divs[d]=false;
        used[d]=false;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}