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
    int N;
    cin>>N;
    vi C(2*N);
    cin>>C;
    vvi chunks;
    chunks.push_back({C[0]});
    for(int i=1;i<2*N;i++){
        if(C[i]<chunks.back()[0]) chunks.back().push_back(C[i]);
        else chunks.push_back({C[i]});
    }
    int k=sz(chunks);
    vi len(k);
    fr(i,k) len[i]=sz(chunks[i]);
    vvb dp(k+1,vb(N+1,false));
    vvb take(k+1,vb(N+1,false));
    dp[0][0]=true;
    for(int i=1;i<=k;i++){
        for(int s=0;s<=N;s++){
            if(dp[i-1][s]) dp[i][s]=true;
            if(s>=len[i-1] && dp[i-1][s-len[i-1]]){
                dp[i][s]=true;
                take[i][s]=true;
            }
        }
    }
    if(!dp[k][N]){
        cout<<-1<<'\n';
        return;
    }
    vi choose(k,0);
    int s=N;
    for(int i=k;i>=1;i--){
        if(take[i][s]){
            choose[i-1]=1;
            s-=len[i-1];
        }
    }
    vi A,B;
    fr(i,k){
        if(choose[i]){
            for(int x:chunks[i]) A.push_back(x);
        }else{
            for(int x:chunks[i]) B.push_back(x);
        }
    }
    cout<<A<<'\n';
    cout<<B<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}