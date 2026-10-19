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

struct Chunk{
    int min_pref;
    int sum;
};

struct Node{
    int min_pref;
    int sum;
    int list_id;
    int idx;
    bool operator<(const Node &other) const{
        return min_pref<other.min_pref;
    }
};

void solve(){
    int x,k;
    cin>>x>>k;
    vector<vector<Chunk>> lists(k);
    fr(i,k){
        int n;
        cin>>n;
        int sum=0;
        int min_pref=0;
        fr(j,n){
            int w;
            cin>>w;
            sum+=w;
            min_pref=min(min_pref,sum);
            if(sum>0){
                lists[i].push_back({min_pref,sum});
                sum=0;
                min_pref=0;
            }
        }
    }
    priority_queue<Node> pq;
    fr(i,k) if(!lists[i].empty()) pq.push({lists[i][0].min_pref,lists[i][0].sum,i,0});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(x+cur.min_pref<0)
            break;
        x+=cur.sum;
        int nxt=cur.idx+1;
        if(nxt<sz(lists[cur.list_id])){
            auto &c=lists[cur.list_id][nxt];
            pq.push({c.min_pref,c.sum,cur.list_id,nxt});
        }
    }
    cout<<x<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}