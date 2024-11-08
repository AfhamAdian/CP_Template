#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define cinall(v,n) {for( int i = 0 ; i<n; i++){ ll t; cin >> t; v.push_back(t); }}

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> arr;
    cinall(arr, n);

    int i = 0, j = 0;
    ll sum = 0;
    ll count = 0;

    while (j < n) {
        sum += arr[j];
        
        while (sum > x && i <= j) {
            sum -= arr[i];
            i++;
        }
        
        if (sum == x) {
            count++;
        }
        
        j++;
    }

    cout << count << endl;
}

int main() {
    fast_io;
    solve();
    return 0;
}
