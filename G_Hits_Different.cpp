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
    for(auto &x:a) cin>>x;
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
    for(auto &x:a) cout<<x<<'\n';
    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a)
{
    int n=a.size();

    if(!n) return cout;

    cout<<a[0];

    for(int i=1;i<n;i++)
        cout<<' '<<a[i];

    return cout;
}

// ===================================END Of the input module ==========================================

const int RC=2023;
const int N_max=RC*(RC+1)/2;

vi dp1(N_max,0);
vi dp2(N_max,0);

void precompute(){
    dp1[0]=1;
    dp2[0]=1;
    int idx=1;
    for(int rc=1;rc<RC;rc++){
        int prev_row=idx-rc;
        for(int i=0;i<=rc;i++){
            int cur=(idx+1)*(idx+1);
            dp1[idx]=cur+(i>0?dp1[prev_row+i-1]:0);
            dp2[idx]=dp1[idx]+(i<rc?dp2[prev_row+i]:0);
            idx++;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    --n;
    cout<<dp2[n]<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}