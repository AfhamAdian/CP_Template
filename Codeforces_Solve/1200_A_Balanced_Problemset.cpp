#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int

void solve() {
    ll x, n;
    cin >> x >> n;

    ll upperLimit = sqrt(x) + 1;
    ll last = -1;

    vector<pair<ll, ll>> divisorMap;
    map<ll, ll> divisorMap2;
    
    if (n == 1 || x == 1) {
        cout << x << endl;
        return;
    }

    for (ll i = 1; i < upperLimit; i++) {
        if (x % i == 0) {
            last = i;
            // divisorMap.push_back(make_pair(i, x / i));
            divisorMap2[i] = x / i;
        }

        if (last >= n) break;
    }


    if (last < n) 
    {
        for( auto it = divisorMap2.rbegin(); it != divisorMap2.rend(); it++)
        {
            if( it->second >= n ) 
            {
                cout << it->first << endl;
                return;
            }
        }
    } else {
        cout << x / last << endl;
    }
}

int main() {
    fast_io;
    bool multi = true;

    if (multi) {
        ll t;
        cin >> t;
        while (t--) solve();
    } else {
        solve();
    }

    return 0;
}
