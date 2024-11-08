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
// #define vi vector<int>
// #define vll vector<ll>

#define cinall(v,n) {for( int i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( int i = 0 ; i<n; i++){ cout <<  v[i] << " "; } cout <<  endl; }

#define pp(ans)  //cout <<  ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"




#include<bits/stdc++.h>

using namespace std;

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<pair<ll,int>> arr;

    for( int i = 0; i<n; i++){
        ll temp;
        cin >> temp;
        arr.pb(mp(temp,i+1));
    }

    sort(arr.begin(), arr.end());

    for( int j = 0; j<n; j++)
    {
        ll zerothNumber = arr[j].first;

        for( int i = 0; i<n; i++)
        {
            // if ( i == j ) continue;
            ll firstNumber = arr[i].first;
            ll requiredSum = x - (firstNumber+zerothNumber);

            int start = 0,end = n-1;
            ll currentSum = 0;

            while( start < end )
            {
                
                if( start == i || start == j ){
                    start++;
                    continue;
                }
                else if ( end == i || end == i ){
                    end--;
                    continue;
                }

                currentSum = arr[start].first + arr[end].first;
                

                if( currentSum == requiredSum ){
                    cout << arr[i].second << " " << arr[start].second << " " << arr[end].second << " " << arr[j].second <<  endl;
                    return;
                }
                else if( currentSum < requiredSum ){
                    start++;
                }
                else{
                    end--;
                }

            }
        }
    }
    cout << "IMPOSSIBLE\n";
}   

int main()
{
    fast_io;
    // bool multi = true;
    bool multi = false;

    if( multi ){
        ll t;
        cin >> t;
        while(t--) solve();
        return 0;
    }

    solve();

	return 0;
}
