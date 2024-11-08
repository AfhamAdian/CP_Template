#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (ll i = a; i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
// #define f first
// #define s second
#define lb lower_bound
#define ub upper_bound
// #define all(x) x.begin(), x.end()
#define ins insert

// #define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long int
// #define vi vector<int>
// #define vll vector<ll>

#define cinall(v, n)               \
    {                              \
        for (ll i = 0; i < n; i++) \
        {                          \
            ll t;                  \
            cin >> t;              \
            v.pb(t);               \
        }                          \
    }
#define coutall(v, n)              \
    {                              \
        for (ll i = 0; i < n; i++) \
        {                          \
            cout << v[i] << " ";   \
        }                          \
        cout << endl;              \
    }

#define pp(ans) // cout <<  ans << endl
#define yes cout << "YES\n"
#define no cout << "NO\n"


// Function to check if the given points form a valid configuration
bool isValid(int pa, int pb, int pc)
{

    // Sort the points in ascending order to match the tuples
    vector<int> point = {pa, pb, pc};
    sort(point.begin(), point.end());
    reverse(point.begin(), point.end());
    // cout << point[0] << " " << point[1] << " " << point[2] << endl;

        if( point[0] == 6 && point[1] == 1 && point[2] == 1)
        {
            return true;
        }
        if( point[0] == 3 && point[1] == 3 && point[2] == 3)
        {
            return true;
        }
        if( point[0] == 4 && point[1] == 4 && point[2] == 1)
        {
            return true;
        }
        return false;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int pa, pb, pc;
        cin >> pa >> pb >> pc;

        if (isValid(pa, pb, pc))
        {
            cout << "Case " << t << ": perfectus" << endl;
        }
        else
        {
            cout << "Case " << t << ": invalidum" << endl;
        }
    }

    return 0;
}
