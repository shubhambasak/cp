#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v.size())
#define srt(v) sort(all(v)
#define rsrt(v) sort(rall(v))
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))
#define unq(v) v.resize(distance(v.begin(),unique(all(v))))
#define bin(x,y) bitset<y>(x)

using namespace std;

const int MOD=1e9+7;

void modadd(int &a,int b){
    a=((a%MOD)+(b%MOD))%MOD;
}

void modsub(int &a,int b){
    a=((a%MOD)-(b%MOD)+MOD)%MOD;
}

void modmul(int &a,int b){
    a=((a%MOD)*(b%MOD))%MOD;
}

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
    int n;
    cin>>n;
    vi ans(n);
    stack<int> pos_left;
    set<int> vals_left;
    fr(i,n){
        pos_left.push(i);
        vals_left.insert(i+1);
    }
    while(sz(pos_left)>=2){
        int x=pos_left.top();
        pos_left.pop();
        int y=pos_left.top();
        pos_left.pop();
        cout<<"? "<<x+1<<" "<<y+1<<endl;
        int a1;
        cin>>a1;
        cout<<"? "<<y+1<<" "<<x+1<<endl;
        int a2;
        cin>>a2;
        int val=max(a1,a2);
        vals_left.erase(val);
        if(a1>a2){
            ans[x]=a1;
            pos_left.push(y);
        }
        else{
            ans[y]=a2;
            pos_left.push(x);
        }
    }
    int v=*vals_left.begin();
    ans[pos_left.top()]=v;
    cout<<"! ";
    for(auto x:ans) cout<<x<<" ";
    cout<<endl<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
