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

struct state{
    int i,j,val;
};

void solve(){
    int n,m;
    cin>>n>>m;
    vvi mat(n,vi(m));
    int si,sj,ei,ej;
    fr(i,n){
        fr(j,m){
            char c;
            cin>>c;
            mat[i][j]=(c=='#')?0:1;
            if(c=='S') si=i,sj=j;
            if(c=='T') ei=i,ej=j;
        }
    }
    auto adj=[&](int i,int j,int val){
        vector<state> ans;
        if(i+1<n && mat[i+1][j] && val!=3) ans.push_back({i+1,j,(val/4==0)?val+1:1});
        if(i-1>=0 && mat[i-1][j] && val!=7) ans.push_back({i-1,j,(val/4==1)?val+1:5});
        if(j+1<m && mat[i][j+1] && val!=11) ans.push_back({i,j+1,(val/4==2)?val+1:9});
        if(j-1>=0 && mat[i][j-1] && val!=15) ans.push_back({i,j-1,(val/4==3)?val+1:13});
        return ans;
    };
    vector<vvi> dp(n,vvi(m,vi(16,LLONG_MAX)));
    queue<state> q;
    q.push({si,sj,0});
    dp[si][sj][0]=0;
    int ans=LLONG_MAX;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto y:adj(x.i,x.j,x.val)){
            if(dp[y.i][y.j][y.val]!=LLONG_MAX)
                continue;
            dp[y.i][y.j][y.val]=dp[x.i][x.j][x.val]+1;
            q.push(y);
        }
        if(x.i==ei && x.j==ej) ans=min(ans,dp[x.i][x.j][x.val]);
    }
    cout<<(ans==LLONG_MAX?-1:ans);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}