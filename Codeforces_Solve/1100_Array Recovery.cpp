#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
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

#define cinall(v,n) {for( int i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( int i = 0 ; i<n; i++){ cout << v[i] << " "; } cout << endl; }

#define pp(ans)  cout << ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"




#include<bits/stdc++.h>

using namespace std;


void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n),d;

    cinall(d,n);
    //coutall(d,n);

    for ( int i = 0; i<n; i++)a
    {
        if( i == 0 )
        {
            a[i] = d[i];
        }
        else 
        {
            if ( d[i] == 0 ) a[i] = a[i-1];
            else if( d[i] > a[i-1] ) a[i] = a[i-1] + d[i];
            else {
                cout << "-1\n";
                return;
            }
        }
    }

    
    coutall(a,n);

}   


int main()
{
    fast_io;
    bool multi = true;
    //bool multi = false;

    if( multi ){
        ll t;
        cin >> t;
        while(t--) solve();
        return 0;
    }

    // solve();

    // int count = 0;
    // string str;
    // cin >> str;

    

	return 0;
}

