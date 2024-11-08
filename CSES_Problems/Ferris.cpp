#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int

void solve() {
    int n;
    cin >> n;

    ll target;
    cin >> target;

    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    int counr = 0;

    int i = 0,j = n-1;

    while( i<j && j<n )
    {
        if(arr[i]+arr[j] <= target)
        {
            i++;
            j--;
            counr++;
        }
        else
        {
            j--;
        }
    }

    cout << n-counr << endl;
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




