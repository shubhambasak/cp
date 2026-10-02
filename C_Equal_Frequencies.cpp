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
    string s;
    cin>>s;
    vector<pair<int,char>> freq(26);
    fr(i,26) freq[i].second='a'+i;
    for(char c:s) freq[c-'a'].first++;
    rsrt(freq);
    int best_k=1,changes=n;
    rep(k,1,26){
        if(n%k) continue;
        int unchanged=0;
        fr(i,k) unchanged+=min(freq[i].first,n/k);
        if(n-unchanged<changes){
            best_k=k;
            changes=n-unchanged;
        }
    }
    map<char,int> mp;
    fr(i,best_k) mp[freq[i].second]=n/best_k;
    string ans(n,' ');
    fr(i,n){
        if(mp[s[i]]>0){
            ans[i]=s[i];
            mp[s[i]]--;
        }
    }
    fr(i,n){
        if(ans[i]!=' ') continue;
        while(!mp.empty() && mp.begin()->second==0) mp.erase(mp.begin());
        char ch=mp.begin()->first;
        ans[i]=ch;
        mp[ch]--;
    }
    cout<<changes<<'\n';
    cout<<ans<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    while(tc--) solve();
    return 0;
}