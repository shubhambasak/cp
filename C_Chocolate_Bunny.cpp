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
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))
#define unq(v) v.resize(distance(v.begin(),unique(all(v))))
#define bin(x,y) bitset<y>(x)

using namespace std;

int MOD=1e9+7;

void modadd(int &a,int b)
{
    a=((a%MOD)+(b%MOD))%MOD;
}

void modsub(int &a,int b)
{
    a=((a%MOD)-(b%MOD)+MOD)%MOD;
}

void modmul(int &a,int b)
{
    a=((a%MOD)*(b%MOD))%MOD;
}

// ================================== take ip/op like vector,pairs directly!==================================

template<typename typC,typename typD>
istream &operator>>(istream &cin,pair<typC,typD> &a)
{
    return cin>>a.first>>a.second;
}

template<typename typC>
istream &operator>>(istream &cin,vector<typC> &a)
{
    for(auto &x:a)
        cin>>x;

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
    for(auto &x:a)
        cout<<x<<'\n';

    return cout;
}

template<typename typC>
ostream &operator<<(ostream &cout,const vector<typC> &a)
{
    int n=a.size();

    if(!n)
        return cout;

    cout<<a[0];

    for(int i=1;i<n;i++)
        cout<<' '<<a[i];

    return cout;
}

// ===================================END Of the input module ==========================================

void solve()
{
    int n;
    cin>>n;

    vi ans(n+1,0);

    int x=1;

    // Find the position containing 1.
    // Compare current candidate with every other position.
    for(int i=2;i<=n;i++)
    {
        cout<<"? "<<x<<" "<<i<<endl;

        int a;
        cin>>a;

        cout<<"? "<<i<<" "<<x<<endl;

        int b;
        cin>>b;

        if(a>b)
        {
            // max(a,b) = min(p[x],p[i])
            // Since a is larger, x contains the smaller value.
            ans[x]=a;
            x=i;
        }
        else
        {
            // i contains the smaller value.
            ans[i]=b;
        }
    }

    // The remaining position gets the remaining value.
    int sum=0;

    for(int i=1;i<=n;i++)
    {
        if(ans[i])
            sum+=ans[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            ans[i]=n*(n+1)/2-sum;
            break;
        }
    }

    cout<<"! ";

    rep(i,1,n)
        cout<<ans[i]<<" ";

    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=1;
    // cin>>T;

    while(T--)
        solve();

    return 0;
}

/*
TC: O(n)
SC: O(n)
*/