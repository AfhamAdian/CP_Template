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
    ll n,t,c;
    cin >> n >> t >> c;

    vector<ll> input;
    cinall(input,n);


    ll ans = input.size()-c+1;

    int prisonersBefore;
    int prisonersAfter;

    for( int i = 0; i<input.size(); i++)
    {
        if( i-c+1 >= 0 ) prisonersBefore = c-1;
        else prisonersBefore = i;

        if ( i+c-1 < input.size() ) prisonersAfter = c-1;
        else prisonersAfter = input.size()-1 -i;

        if( input[i] > t && c != 1 )
        {
            if( prisonersBefore == c-1 && prisonersAfter == c-1 )
            {
                ans -= c;
                i += c-1;
            }
            else if( prisonersBefore == c-1 )
            {
                ans = ans - ( prisonersAfter+1 );
                i += prisonersAfter;
            }
            else if( prisonersAfter == c-1 )
            {
                ans = ans - ( prisonersBefore+1 );
                i += c-1;
            }
            else
            {
                ans = 0;
                break;
            }
        }
        else if ( input[i] > t && c == 1)
        {
            ans--;
        }
        else {
            cout << "marebaap" << endl;
        }
    }

    cout << ans << endl;

}

int main()
{
    fast_io;
    // bool multi = true;
    bool multi = false;

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