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
#define coutall(v,n) {for( int i = 0 ; i<n; i++){ //cout <<  v[i] << " "; } //cout <<  endl; }

#define pp(ans)  //cout <<  ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"



#include<bits/stdc++.h>

using namespace std;

void solve ()
{
    int n;
    cin >> n;

    vector<ll> arrA;
    vector<ll> arrB;

    cinall(arrA,n);
    cinall(arrB,n+1);

    ll ans = 0;
    int flag = 0;

    ll lastElementArrB = arrB[n];
    ll minDiff = INT32_MAX;

    for( int i = 0; i<n; i++)
    {
        if( lastElementArrB >= arrA[i] && lastElementArrB <= arrB[i]
            || lastElementArrB >= arrB[i] && lastElementArrB <= arrA[i] )
        {
            flag = 1;
            minDiff = 0;
            ans += 1;
            break;
        }
    }

    if( flag == 0 )
    {
        for( int i = 0; i<n; i++)
        {
            ll temp = min( abs(arrA[i]-lastElementArrB ), abs( arrB[i]-lastElementArrB ) );
            if( temp < minDiff ) minDiff = temp;
        }
        
        if ( minDiff == 0 ) ans += 1;
        else ans += ( minDiff+1 );
    }

    // cout << minDiff << " ok " << endl;


    for( int i = 0; i<n; i++)
    {
        ans += abs( arrA[i] - arrB[i] );
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
        //cout << t << endl;
        while(t--) solve();
        return 0;
    }

    solve();

	return 0;
}

    // for( int i = 0; i<arr.size(); i++)
    // {
    //     cout << arr[i].second << " ";
    // }
    // cout << endl;