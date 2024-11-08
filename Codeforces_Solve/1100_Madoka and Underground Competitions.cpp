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

void solve ()
{
    ll n,k,r,c, gap1 = 0, gap2 = 0;
    cin >> n >> k >> r >> c;

    vector <ll> row( n, -1 );
    ll a[n][n];

    for( int i = 0; i<n; i++)
    {
        for( int j = 0; j<n; j++)
        {
            a[i][j] = -2;
        }
    }

    //coutall( row, n );
    
    row[c-1] = 0;

    for( int i = c-1; i>=0; i = i-k )
    {
        row[i] = 0;
    }
    for( int i = c-1; i<n; i = i + k )
    {
        row[i] = 0;
    }

    
    for( int i = 0; i<n; i++)
    {
        if( row[i] == 0 ) {
            gap1 = i+1;
            break;
        }
    }
    for ( int i = n-1; i>=0; i--)
    {
        if( row[i] == 0 ) {
            gap2 = n-(i+1);
            break;
        }
    }

    ll gap = gap1 + gap2;
    ll tempGap = gap2;
    vector<ll> rowLast,tempRow;
    rowLast = row;

    while( tempGap > 0 )
    {
        ll temp = rowLast.back();
        rowLast.pop_back();
        rowLast.insert( rowLast.begin(), temp );
        tempGap--;
    }

    tempGap = gap1+1;
    tempRow = row;

    for( int i = r-1; i>= 0; i-- )
    {
        // if( tempGap == 0)
        // {
        //     tempRow = rowLast;
        //     tempGap = gap;
        //     cout << "gap: " << gap << endl;
        // }
        
        for( int j = 0; j<n; j++)
        {   
           //cout << tempRow[j] << " ";
            a[i][j] = tempRow[j];
        }
        //cout << endl;

        ll temp = tempRow.front();
        tempRow.erase(tempRow.begin());
        tempRow.pb(temp);
        tempGap--;
    }   

    tempRow = row;
    
    for ( int i = r-1; i<n; i++)
    {
        for( int j = 0; j<n; j++)
        {
            //cout << tempRow[j] << " ";
            a[i][j] = tempRow[j];
        }
        //cout << endl;

        ll temp = tempRow.back();
        tempRow.pop_back();
        tempRow.insert(tempRow.begin(), temp);
    }

    //cout << "\n\n\n";
    for( int i = 0; i<n; i++)
    {
        for( int j = 0; j<n; j++)
        {
            if( a[i][j] == 0 ) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }


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

