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

// #define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
// #define vi vector<int>
// #define vll vector<ll>

#define cinall(v,n) {for( ll i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( ll i = 0 ; i<n; i++){ cout <<  v[i] << " "; } cout <<  endl; }

#define pp(ans)  //cout <<  ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"



    // -Examine Test Cases
    // -Analyze why it is behaving that way
    // -Come with a Hypothesis
    // -Disprove the Hypothesis
    
    // -Prepare a code outline
    // -check if the code outline validates the test cases
    // -code
    // -think of corner case before submitting 


void solve()
{
    ll n,k;
    cin >> n >> k;

    vector<ll> v;
    cinall(v,n);    

    ll l = -1;
    ll r = 0;

    for( int i = 0; i < n; i++)
    {
        l = max(l,v[i]);
        r += v[i];
    }

    auto isValid = [&](ll mid ) -> bool {

        ll partitions = 1;
        ll sum = 0;
        for( int i = 0; i<n; i++ ){
            sum += v[i];
            if( sum > mid ){
                sum = v[i];
                partitions++;
            }
        }
        return partitions <= k;
    };

    ll ans = r;
    while( l <= r )
    {
        ll mid = l + (r-l)/2;
        if( isValid(mid) ){
            ans = mid;
            r = mid-1;
        }else {
            l = mid+1;
        }
    }

    cout << ans << endl;
}   

int main()
{
    fast_io;
    // bool multi = true;
    bool multi = false;

    if (multi) {
        ll t;
        cin >> t;
        while (t--) solve();
        return 0;
    }

    solve();

    return 0;
}