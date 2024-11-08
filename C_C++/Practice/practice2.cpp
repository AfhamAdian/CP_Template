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

// #define all(x) (x).begin(), (x).end())
// #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin()))

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

// -Examine Test Cases
// -Analyze why it is behaving that way
// -Come with a Hypothesis
// -Disprove the Hypothesis

// -Prepare a code outline
// -check if the code outline validates the test cases
// -code
// -think of corner case before submitting

void solve(ll y)
{
    vector<ll> v;
    // cinall(v, 3);
    // sort(v.begin(), v.end());

    string a1, a2, a3;
    a1 = "abd";
    a2 = "bcd";
    a3 = "acd";

    vector<string> vs;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                string temp = "abc";
                temp[0] = a1[i];
                temp[1] = a2[j];
                temp[2] = a3[k];

                vs.pb(temp);
            }
        }
    }

    vector<vector<ll>> v2;
    set<tuple<ll, ll, ll>> s;

    for (int i = 0; i < vs.size(); i++)
    {
        string tempo = vs[i];
        ll pointsa = 0;
        ll pointsb = 0;
        ll pointsc = 0;

        if (tempo[0] == 'a')
            pointsa += 3;
        else if (tempo[0] == 'b')
            pointsb += 3;
        else
        {
            pointsa += 1;
            pointsb += 1;
        }

        if (tempo[1] == 'b')
            pointsb += 3;
        else if (tempo[1] == 'c')
            pointsc += 3;
        else
        {
            pointsc += 1;
            pointsb += 1;
        }

        if (tempo[2] == 'c')
            pointsc += 3;
        else if (tempo[2] == 'a')
            pointsa += 3;
        else
        {
            pointsa += 1;
            pointsc += 1;
        }

        vector<ll> v1 = {pointsa, pointsb, pointsc};
        sort(v1.begin(), v1.end());
        // cout << v1[0] << " " << v1[1] << " " << v1[2] << endl;
        s.insert(make_tuple(v1[0], v1[1], v1[2]));
        // if (v1 == v)
        // {
        //     cout << "Case " << y << ": perfectus" << endl;
        //     return;
        // }
    }
    for (const auto &tuple : s) {
        cout << get<0>(tuple) << " " << get<1>(tuple) << " " << get<2>(tuple) << endl;
    }

    // cout << "Case " << y << ": invalidum" << endl;
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
        for (int i = 1; i <= t; i++)
        {
            solve(i);
        }
        return 0;
    }

    // solve();

    return 0;
}