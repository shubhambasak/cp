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
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

/*
void solve(){
    int n,x;
    cin >> n >> x;
    
    vi a(n);
    fr(i,n){
        cin >> a[i];
    }
    
    int max = 0;
    int temp = 0;
    
    if(n > 0){
        max = a[0];
        
        rep(i,1,n){
            temp = a[i] - a[i-1];
            if (temp > max) max = temp;
        }
        
        temp = 2 * (x - a[n-1]);
        if (temp > max) max = temp;
    }
    
    cout << max << "\n";
}*/


/*
void solve(){
int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n, x; 
        cin >> n >> x;
        vi points_arr; 
        points_arr.push_back(0);
        fr(i,n)
        {
            int point;
            cin >> point; 
            points_arr.push_back(point); 
        }
        points_arr.push_back(x); 
        n = points_arr.size(); 
        
        int max_distance_between_points = INT_MIN;  
        fr(i,n)
        {
            if (i == n - 1) {
                max_distance_between_points = max(max_distance_between_points, 2 * (points_arr[i] - points_arr[i - 1])); 
            }
            else{
                max_distance_between_points = max(max_distance_between_points, points_arr[i] - points_arr[i - 1]); 
            }
        }
        cout << max_distance_between_points << endl;
    }
}
*/

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    fr(i,n) cin >> a[i];

    int max_gap = a[0];
    for (int i = 0; i + 1 < n; ++i) max_gap = max(max_gap, a[i+1] - a[i]);
    max_gap = max(max_gap, x - a[n-1]);

    int ans = max(max_gap, 2 * (x - a[n-1]));
    cout << ans << "\n";
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
