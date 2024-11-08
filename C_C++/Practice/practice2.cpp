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
    char a, b;
    cin >> a >> b;
    ll pos1 = a-'!';
    ll pos2 = b-'!';

    for( int i = 1; i<=94; i++)
    {
        if( pos1%i == pos2%i)
        {
            cout << i << " " << (94 + i - 1) / i << endl;
        }
    }
    cout << endl;
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