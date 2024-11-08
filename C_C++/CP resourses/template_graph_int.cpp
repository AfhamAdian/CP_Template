#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long int

#define cinall(v, n)                \
    {                               \
        for (int i = 0; i < n; i++) \
        {                           \
            int t;                  \
            cin >> t;               \
            v.pb(t);                \
        }                           \
    }
#define coutall(v, n)               \
    {                               \
        for (int i = 0; i < n; i++) \
        {                           \
            cout << v[i] << " ";    \
        }                           \
        cout << endl;               \
    }

#define pp(ans) // cout <<  ans << endl
#define yes cout << "YES\n"
#define no cout << "NO\n"

int pow_int(int base, int exp)
{
    int result = 1;
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
void dfs(int current_node, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (visited[current_node])
        return;
    visited[current_node] = true;

    for (int neighbor : adj[current_node])
        dfs(neighbor, adj, visited);
}

// BFS on adjacency list O(V+E)
void bfs(int start_node, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
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
vector<int> dijkstra(int start_node, vector<vector<pair<int, int>>> &adj, int n, vector<int> &parent)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_node])
            continue;

        for (auto &edge : adj[current_node])
        {
            int neighbor = edge.first;
            int weight = edge.second;

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
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);

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

int kruskal(int n, vector<pair<int, pair<int, int>>> &edges)
{
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int mst_weight = 0;

    for (auto &edge : edges)
    {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.find(u) != ds.find(v))
        {
            ds.unite(u, v);
            mst_weight += weight;
        }
    }

    return mst_weight;
}

void track_parent(int child_node, vector<int> &ans, vector<int> &parent)
{
    ans.pb(child_node);
    int parent_node = parent[child_node];
    if (parent_node == -1)
        return;
    track_parent(parent_node, ans, parent);
}

// solve function

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    vector<int> parent(n, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb({b, -1});
    }

    vector<int> dist = dijkstra(0, graph, n, parent);
    int distn = dist[n - 1];
    if (distn == INT_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << -1 * distn + 1 << endl;

    vector<int> ans;

    track_parent(n - 1, ans, parent);
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x + 1 << " ";
    cout << endl;
}

int main()
{
    fast_io;
    bool multi = false;

    if (multi)
    {
        int t;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }

    solve();
    return 0;
}
