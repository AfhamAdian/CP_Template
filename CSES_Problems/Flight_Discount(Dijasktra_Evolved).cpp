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

void dijkstra(ll start, ll n, vector<vector<pair<ll, ll>>> &adj, vector<ll> &dist, vector<ll> &edgeMax)
{
    // if( start == 0 ){
    edgeMax[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        ll vertex = pq.top().second;
        ll weight = pq.top().first;
        pq.pop();

        if (weight > dist[vertex])
            continue;
        for (auto edges : adj[vertex])
        {
            ll to = edges.first;
            ll len = edges.second;

            if (dist[vertex] + len < dist[to])
            {
                dist[to] = dist[vertex] + len;
                pq.push({dist[to], to});
                edgeMax[to] = max(edgeMax[vertex], len);
            }
        }
    }
    //  }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> directEdge;
    vector<vector<pair<ll, ll>>> adj(n);
    vector<vector<pair<ll, ll>>> rev(n);
    vector<ll> dist(n, LLONG_MAX);
    vector<ll> edgeMax(n, 0);
    vector<ll> edgeMaxRev(n, 0);
    vector<ll> distRev(n, LLONG_MAX);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            directEdge.pb({b - 1, c});
        }

        adj[--a].pb({--b, c});
        rev[b].pb({a, c});
    }
    dijkstra(0, n, adj, dist, edgeMax);
    dijkstra(n - 1, n, rev, distRev, edgeMaxRev);

    ll midDist = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        // dist to 1 to i
        ll dist1 = dist[i];
        ll edgeMax1 = edgeMax[i];

        // dist to i to n
        ll dist2 = distRev[i];
        ll edgeMax2 = edgeMaxRev[i];

        ll finalEdgeMax = max(edgeMax1, edgeMax2);
        if (dist1 != LLONG_MAX && dist2 != LLONG_MAX)
        {
            midDist = min(midDist, dist1 + dist2 - finalEdgeMax + finalEdgeMax / 2);
        }
    }

    for (auto x : directEdge)
    {
        // dist to 1 to i
        // cout << x.first << " " << x.second << endl;
        ll i = x.first;

        ll dist1 = x.second;
        ll edgeMax1 = x.second;

        // dist to i to n
        ll dist2 = distRev[i];
        ll edgeMax2 = edgeMaxRev[i];

        ll finalEdgeMax = max(edgeMax1, edgeMax2);
        // cout << dist1 << " " << dist2 << " " << finalEdgeMax << endl;
        if (dist1 != LLONG_MAX && dist2 != LLONG_MAX)
        {
            midDist = min(midDist, dist1 + dist2 - finalEdgeMax + finalEdgeMax / 2);
        }
    }
    cout << midDist << endl;
}

int main()
{
    fast_io;
    // bool multi = true;
    bool multi = false;

    if (multi)
    {
        ll t;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }

    solve();

    return 0;
}