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

void solve(){
    int N;
    cin>>N;
    vi A(N);
    for(auto &x:A){
        cin>>x;
        --x;
    }
    vi cnt(N,0);
    vi is_last(N,0);
    vi last_pos(N,-1);
    for(int i=N-1;i>=0;i--){
        if(!cnt[A[i]]++){
            is_last[i]=1;
            last_pos[A[i]]=i;
        }
    }
    vi ans;
    multiset<int> st;
    int l=0;
    int r=-1;
    int flag=0;
    while(r+1<N){
        while(r+1<N && (r==-1 || !is_last[r])){
            ++r;
            if(is_last[last_pos[A[r]]]) st.emplace(A[r]);
        }
        if(sz(st)){
            ans.push_back(flag ? *st.begin() : *st.rbegin());
            flag^=1;
            is_last[last_pos[ans.back()]]=0;
            while(A[l]!=ans.back()){
                auto it=st.find(A[l++]);
                if(it!=st.end()) st.erase(it);
            }
            st.erase(A[l++]);
        }
    }
    cout<<sz(ans)<<endl;
    fr(i,sz(ans)) cout<<ans[i]+1<<" \n"[i==sz(ans)-1];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}