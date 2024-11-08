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

ll pow_ll(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

// DFS on adjacency list O(V+E)
void dfs(ll current_node, vector<vector<ll>> &adj, vector<bool> &visited)
{
    if (visited[current_node])
        return;
    visited[current_node] = true;

    for (int neighbor : adj[current_node])
        dfs(neighbor, adj, visited);
}

// BFS on adjacency list O(V+E)
void bfs(ll start_node, vector<vector<ll>> &adj, vector<bool> &visited)
{
    queue<ll> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();

        for (int neighbor : adj[current_node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// dijakstra
vector<ll> dijkstra(ll start_node, vector<vector<pair<ll, ll>>> &adj, ll n, vector<ll> &parent)
{
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        ll current_dist = pq.top().first;
        ll current_node = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_node])
            continue;

        for (auto &edge : adj[current_node])
        {
            ll neighbor = edge.first;
            ll weight = edge.second;

            if (dist[current_node] + weight < dist[neighbor])
            {
                parent[neighbor] = current_node;
                dist[neighbor] = dist[current_node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}

// MST
struct DisjointSet
{
    vector<ll> parent, rank;

    DisjointSet(ll n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (ll i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    ll find(ll u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(ll u, ll v)
    {
        ll root_u = find(u);
        ll root_v = find(v);

        if (root_u != root_v)
        {
            if (rank[root_u] > rank[root_v])
            {
                parent[root_v] = root_u;
            }
            else if (rank[root_u] < rank[root_v])
            {
                parent[root_u] = root_v;
            }
            else
            {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

ll kruskal(ll n, vector<pair<ll, pair<ll, ll>>> &edges)
{
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    ll mst_weight = 0;

    for (auto &edge : edges)
    {
        ll weight = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;

        if (ds.find(u) != ds.find(v))
        {
            ds.unite(u, v);
            mst_weight += weight;
        }
    }

    return mst_weight;
}

void track_parent(ll child_node, vector<ll> &ans, vector<ll> &parent)
{
    ans.pb(child_node);
    ll parent_node = parent[child_node];
    if (parent_node == -1)
        return;
    track_parent(parent_node, ans, parent);
}

// -Examine Test Cases
// -Analyze why it is behaving that way
// -Come with a Hypothesis
// -Disprove the Hypothesis

// -Prepare a code outline
// -check if the code outline validates the test cases
// -code
// -think of corner case before submitting

// solve function

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n);
    vector<ll> parent(n, -1);

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb({b, -1});
    }

    vector<ll> dist = dijkstra(0, graph, n, parent);
    cout << -1 * dist[n - 1] + 1 << endl;

    vector<ll> ans;

    track_parent(n - 1, ans, parent);
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x + 1 << " ";
    cout << endl;
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