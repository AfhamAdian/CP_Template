#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
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

// #define all(x) (x).begin(), (x).end())
// #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin()))

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
// #define vi vector<int>
// #define vll vector<ll>

#define cinall(v,n) {for( ll i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( ll i = 0 ; i<n; i++){ cout <<  v[i] << " "; } cout <<  endl; }

#define pp(ans)  //cout <<  ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"

ll pow_ll(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

//solve function
void solve()
{
    ll n;
    cin >> n;

    vector<ll> a, b, c;
    cinall(a, n);
    cinall(b, n);
    cinall(c, n);

    ll total = accumulate(a.begin(), a.end(), 0LL);
    total = ceil((double)total / 3);

    pair<ll, ll> p1, p2, p3;
    ll flag = 0;

    auto f = [&](vector<ll> &v1, vector<ll> &v2, vector<ll> &v3, int count) {

        if( flag == 1) return;
        ll temp = 0;
        int i;
        p1.first = 1;
        for (i = 0; i < n; i++) {
            temp += v1[i];
            if (temp >= total) {
                p1.second = i + 1;
                // cout << count << " " << p1.second << endl;
                break;
            }
        }

        if (i == n) return;
        temp = 0;
        p2.first = p1.second + 1;
        for ( ; i < n; i++) {
            temp += v2[i];
            if (temp >= total) {
                
                p2.second = i + 1;
                // cout << count << " " << p2.second << endl;
                break;
            }
        }

        if (i == n) return;
        temp = 0;
        p3.first = p2.second + 1;
        for ( ; i < n; i++) {
            temp += v3[i];
            if (temp >= total) {
                p3.second = i + 1;
                // cout << count << " " << p3.second << endl;
                break;
            }
        }

        if (i == n && count == 6) {
            cout << "-1" << endl;
        } else if (i == n) {
            return;
        } else {
            // cout << count << endl;
            flag = 1;
        }
    };

    f(a, b, c, 1);
    if( flag == 1 ){
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << " " << p3.first << " " << max(p3.second,n) << endl;
        return;
    }
    f(a, c, b, 2);
        if( flag == 1 ){
        cout << p1.first << " " << p1.second << " " << p3.first << " " << max(p3.second,n) << " " << p2.first << " " << p2.second << endl;
        return;
    }
    f(b, a, c, 3);
        if( flag == 1 ){
        cout << p2.first << " " << p2.second << " " << p1.first << " " << p1.second << " " << p3.first << " " << max(p3.second,n) << endl;
        return;
    }
    f(b, c, a, 4);
        if( flag == 1 ){
        cout << p3.first << " " << max(p3.second ,n)<< " " << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
        return;
    }
    f(c, a, b, 5);
        if( flag == 1 ){
        cout << p2.first << " " << p2.second << " " << p3.first << " " << max(p3.second,n) << " " << p1.first << " " << p2.second << endl;
        return;
    }
    f(c, b, a, 6);
        if( flag == 1 ){
        cout << p3.first << " " << max(p3.second,n) << " " << p2.first << " " << p2.second << " " << p1.first << " " << p1.second << endl;
        return;
    }
}

int main()
{
    fast_io;
    bool multi = true;
    // bool multi = false;

    if (multi) {
        ll t;
        cin >> t;
        while (t--) solve();
        return 0;
    }

    solve();

    return 0;
}