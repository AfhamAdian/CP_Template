#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int

void solve() {
    int n;
    cin >> n;

    vector<ll> arr;
    for( int i = 0; i<n; i++)
    {
        ll t;
        cin >> t;
        arr.push_back(t);
    }

    multiset<ll> towerSet;
    
    int count = 0;

    for( int i = 0; i<n; i++)
    {
        auto it =  towerSet.upper_bound(arr[i]);

        if ( it == towerSet.end() )
        {
            towerSet.insert(arr[i]);
            count++;
        }
        else
        {
            towerSet.erase(it);
            towerSet.insert(arr[i]);
        }
    }

    cout << count << endl;
}

int main() {
    fast_io;
    // bool multi = true;

    // if (multi) {
    //     ll t;
    //     cin >> t;
    //     while (t--) solve();
    // } else {
    //     solve();
    // }

    solve();

    return 0;
}




