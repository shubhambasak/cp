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

void solve(){
    int n;
    cin>>n;
    vi a(n);
    cin>>a;

    int best=0,bestl=0,bestr=n;
    int l=0;

    while(l<n){
        if(a[l]==0){
            l++;
            continue;
        }
        int r=l-1,tc=0,neg=1;
        while(r+1<n&&a[r+1]!=0){
            r++;
            if(abs(a[r])==2) tc++;
            if(a[r]<0) neg*=-1;
        }
        if(neg==1){
            if(tc>best){
                bestl=l;
                bestr=n-1-r;
                best=tc;
            }
            l=r+1;
            continue;
        }
        int ntc=tc,leftIdx=l-1;
        do{
            leftIdx++;
            ntc-=(abs(a[leftIdx])==2);
        }while(a[leftIdx]>0);
        if(ntc>best){
            bestl=leftIdx+1;
            bestr=n-1-r;
            best=ntc;
        }
        int nr=r+1;
        ntc=tc;
        do{
            nr--;
            ntc-=(abs(a[nr])==2);
        }while(a[nr]>0);
        if(ntc>best){
            bestl=l;
            bestr=n-nr;
            best=ntc;
        }
        l=r+1;
    }
    cout<<bestl<<" "<<bestr<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}
