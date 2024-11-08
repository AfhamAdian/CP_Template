#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
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

#define cinall(v, n)                \
    {                               \
        for (int i = 0; i < n; i++) \
        {                           \
            ll t;                   \
            cin >> t;               \
            v.pb(t);                \
        }                           \
    }
#define coutall(v, n)               \
    {                               \
        for (int i = 0; i < n; i++) \
        { // cout <<  v[i] << " "; } //cout <<  endl; }

#define pp(ans) // cout <<  ans << endl
#define yes cout << "YES\n"
#define no cout << "NO\n"

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string str;

    cin >> str;

    int from, to, status = 404, cost = 0, m = -1;

    from = str[0] - 'a';
    to = str[str.size() - 1] - 'a';

    if (from < to)
        status = -1;
    else if (from > to)
        status = 1;
    else
        status = 0;

    vector<pair<int, int>> arr;

    for (int i = 0; i < str.size(); i++)
    {
        if (i == 0 || i == str.size() - 1)
            continue;
        if ((str[i] - 'a') <= max(from, to) && (str[i] - 'a') >= min(from, to))
        {
            // cout << "s " << str[i] << endl;
            arr.pb(make_pair(str[i] - 'a', i + 1));
        }
    }

    if (status == 1)
    {
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
    }
    else
        sort(arr.begin(), arr.end());

    if (arr.size() > 1)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            cost += abs(arr[i].first - arr[i + 1].first);
        }

        cost += abs(from - arr[0].first);
        cost += abs(to - arr[arr.size() - 1].first);
    }
    else
    {
        cost += abs(from - to);
    }

    m = arr.size() + 2;
    cout << cost << " " << m << endl;

    cout << "1 ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].second << " ";
    }
    cout << str.size() << endl;
}

int main()
{
    fast_io;
    bool multi = true;
    // bool multi = false;

    if (multi)
    {
        ll t;
        cin >> t;
        // cout << t << endl;
        while (t--)
            solve();
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