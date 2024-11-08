#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
// #define f first
// #define s second
#define lb lower_bound
#define ub upper_bound
//#define all(x) x.begin(), x.end()
#define ins insert

// #define all(x) (x).begin(), (x).end())
// #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin()))

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
// #define vi vector<int>
// #define vll vector<ll>

#define cinall(v,n) {for( ll i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( ll i = 0 ; i<n; i++){ cout <<  v[i] << " "; } cout <<  endl; }

#define pp(ans)  //cout <<  ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"

ll pow_ll(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

//solve function
void solve()
{   
    ll n;
    cin >> n;

    vector<ll> arr;
    ll pos[200000] = {-1};
    cinall(arr, n);

    for( int i = 0; i<n; i++){
       pos[arr[i]-1] = i; 
    }

    ll count = 1;
    for( int i = 0; i<n-1; i++){
        if(pos[i] > pos[i+1]){
            count++;
        }
    }
    cout << count << endl;
}


int main()
{
    fast_io;
    ll t=1;
    while (t--) solve();
    return 0;
}