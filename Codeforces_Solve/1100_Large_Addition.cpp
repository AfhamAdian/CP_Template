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
    ll inputNumber;
    cin >> inputNumber;

    string inputString = to_string(inputNumber);

    int digits = inputString.size();
    // cout << inputString << endl;

    if( inputString[0] != '1')
    {
        no;
        return;
    }
    else if ( inputString.size() == 2 )
    {
        if( inputNumber >= 10 && inputNumber <= 18 ) yes;
        else no;
        return;
    }

    // for( int i = 0; i < digits-2; i++)
    // {
    //     int j = 0;
    //     string temp = inputString;
    //     string upperLimitString = "";

    //     while( j<=i )
    //     {
    //         if( j == 0 ) temp[ temp.size()-1-j ] = '8';
    //         else temp[ temp.size()-1-j ] = '9';

    //         if( j == i ) upperLimitString += '2';
    //         else upperLimitString += '1';

    //         j++;
    //     }
    //     cout << upperLimitString << endl;
    //     cout << temp << endl;

    //     ll tempLowerLimitNumber = stoll(temp);
    //     ll UpperLimitNumber = stoll(upperLimitString);
    //     ll tempUpperLimit =  + UpperLimitNumber;

    //     if( tempLowerLimitNumber > inputNumber && i == 0)
    //     {
    //         no;
    //         return;
    //     }
        
    //     if( inputString[ digits-1 ] == '9' && i == 0 )
    //     {
    //         inputString[ digits-1 ] = '7';
    //         ll tempAfterSwitching = stoll(inputString);

    //         if( tempLowerLimitNumber > tempAfterSwitching )
    //         {
    //             no;
    //             return;
    //         }
    //     }

    //     if( inputNumber > tempLowerLimitNumber && inputNumber < tempUpperLimit )
    //     {
    //         no;
    //         return;
    //     }
    // } 
    
    // yes;

    for ( int i = 1; i < digits-1; i++)
    {
        if ( inputString[i] == '0' )
        {
            no;
            return;
        }
    }
    if ( inputString[ digits-1 ] == '9' )
    {
        no;
        return;
    }
    yes;

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