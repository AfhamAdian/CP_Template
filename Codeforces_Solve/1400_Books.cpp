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
    int n;
    cin >> n;

    ll t;
    cin >> t;

    vector<int> arr;
    vector<int> prefixArr;
    cinall(arr,n);

    int sum = 0;
    for( int i = 0; i<n; i++)
    {
        sum += arr[i];
        prefixArr.pb(sum);
    }

    int numberOfBooks = 0;
    int maxBooks = -1;

    for( int i = 0; i<n; i++)
    {
        int left = i, right = n-1;
        int result = -1;
        int resultIndex = -1;
        int num;

        while( left <= right )
        {
            int middle = (left+right)/2;
            
            if( i != 0 ) num = prefixArr[middle] - prefixArr[i-1];
            else num = prefixArr[middle];

            if( num == t )
            {
                result = num;
                resultIndex = middle;
                break;
            }
            else if( num < t )
            {
                result = num;
                resultIndex = middle;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        // cout << resultIndex << " " << result << endl;
        
        if( resultIndex == -1 ) numberOfBooks = 0;
        else numberOfBooks = resultIndex - i + 1;

        maxBooks = max(maxBooks, numberOfBooks);
    }
    cout << maxBooks << endl;
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
