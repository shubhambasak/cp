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

bool check(int H,int W,vector<pair<int,int>> a){
    multiset<pair<int,int>> sh,sw;

    for(auto &p:a){
        sh.insert({p.first,p.second});
        sw.insert({p.second,p.first});
    }

    while(!sh.empty()){
        auto itw=prev(sw.end());
        auto ith=prev(sh.end());

        if(itw->first==W){
            int h=itw->second;
            sw.erase(itw);
            sh.erase(sh.find({h,W}));
            H-=h;
        }
        else if(ith->first==H){
            int w=ith->second;
            sh.erase(ith);
            sw.erase(sw.find({w,H}));
            W-=w;
        }
        else return false;
    }

    return true;
}

void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);
    int area=0,maxh=0,maxw=0;

    fr(i,n){
        cin>>a[i].first>>a[i].second;
        area+=a[i].first*a[i].second;
        maxh=max(maxh,a[i].first);
        maxw=max(maxw,a[i].second);
    }

    vector<pair<int,int>> ans;

    if(area%maxw==0){
        int h=area/maxw;
        if(check(h,maxw,a))
            ans.push_back({h,maxw});
    }

    if(area%maxh==0){
        int w=area/maxh;
        if(check(maxh,w,a))
            ans.push_back({maxh,w});
    }
    srt(ans);
    ans.erase(unique(all(ans)),ans.end());
    cout<<ans.size()<<"\n";
    for(auto &p:ans)
        cout<<p.first<<' '<<p.second<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}