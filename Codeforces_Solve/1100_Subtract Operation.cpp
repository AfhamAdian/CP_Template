#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define lb lower_bound
#define ub upper_bound
//#define all(x) x.begin(), x.end()
#define ins insert

//#define all(x) (x).begin(), (x).end()
//#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int

#define cinall(v,n) {for( int i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( int i = 0 ; i<n; i++){ /*cout <<  v[i] << " "; */ } /*cout <<  endl; */}

#define pp(ans) /*cout <<  ans << endl */
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"

#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    ll k;
    cin >> k;

    vector<ll> input;
    cinall(input, n);

    bool ans = false;

    sort(input.begin(), input.end());

    int i = 0, j = 0;

    while (j < n)
    {
        if (i == j) j++;  // Ensure i and j are not the same
        if (j >= n) break;

        ll diff = input[j] - input[i];

        if (diff == k)
        {
            ans = true;
            break;
        }
        else if (diff < k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    if (ans) yes;
    else no;
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
