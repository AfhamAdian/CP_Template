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


void solve()
{
    ll n,k;
    cin >> n >> k;

    vector<ll> h,a;
    cinall(a,n);
    cinall(h,n);

    vector<pair<ll,ll>> segment;
    ll l = 0;
    for( int i=0; i<n; i++)
    {   
        ll prev = i;
        while( i+1<n && h[i]%h[i+1] == 0 )
        {
            i++;
        }
        segment.pb({prev,i});
    }

    ll maxn = 0;
    for( int i=0; i<segment.size(); i++)
    {
        ll segmentStart = segment[i].first;
        ll segmentEnd = segment[i].second;

        ll fi = segmentStart;
        ll la = segmentStart;
        ll sum = 0;

        while( fi <= la && la <= segmentEnd )
        {
            sum += a[la];

            if( sum > k ){
                while( sum > k && fi <= la )
                {
                    sum -= a[fi];
                    fi++;
                }
                maxn = max(maxn,la-fi+1);
            }

            maxn = max(maxn,la-fi+1);
            la++;
        }
    }

    cout << maxn << endl;
}

int main()
{
    fast_io;
    bool multi = true;
    // bool multi = false;

    if (multi) {
        ll t;
        cin >> t;
        while (t--) solve();
        return 0;
    }

    solve();

    return 0;
}