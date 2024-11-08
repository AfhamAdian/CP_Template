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




#include<bits/stdc++.h>

using namespace std;

void solve()
{
    ll n,m;
    cin >> n >> m;

    vector<ll> v;
    cinall(v,n);

    vector<int> mod(m,0);
    for( int i = 0; i<n; i++)
    {
        mod[v[i]%m]++;
    }

    if( n == 1 ){
        cout << 1 << endl;
        return;
    }
    
    ll ans = 0;
    for( int i = 0; i<m; i++)
    {
        if( i == 0 ){
            if( mod[i] != 0 )   ans += 1;
        }
        else if ( i == m-i && mod[i] != 0 ) ans += 1;
        else
        {
            if( mod[i] == 0 && mod[m-i] == 0 ) {}
            else if( mod[i] == 0 ) ans += mod[m-i];
            else if ( mod[m-i] == 0 ) ans += mod[i];
            else if ( mod[i] > mod[m-i] ){
                ans += 1;
                ans += max(0,abs(mod[i] - mod[m-i]) - 1);
            }
            else if ( mod[i] < mod[m-i] ){
                ans += 1;
                ans += max(0,abs(mod[i] - mod[m-i]) - 1);
            }
            else{
                ans += 1;
            }
            mod[i] = 0;
            mod[m-i] = 0;
        }
    }

    cout << ans << endl;
}   

int main()
{
    fast_io;
    bool multi = true;
    // bool multi = false;

    if( multi ){
        ll t;
        cin >> t;
        while(t--) solve();
        return 0;
    }

    solve();

	return 0;
}
