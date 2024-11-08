#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

void track_parent(int child_node, vector<int> &ans, vector<int> &parent)
{
    ans.pb(child_node);
    int parent_node = parent[child_node];
    if (parent_node == -1)
        return;
    track_parent(parent_node, ans, parent);
}

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
    // track_parent(n - 1, ans, parent);
    // reverse(ans.begin(), ans.end());
    // for (auto x : ans)
    //     cout << x + 1 << " ";
    // cout << endl;
}

int main()
{
    fast_io;

    // Redirect input from file
    ifstream infile("input_1.txt");
    if (!infile)
    {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    cin.rdbuf(infile.rdbuf());
    cout << "Execution started" << endl;
    bool multi = false;

    if (multi)
    {
        int t;
        cin >> t;
        while (t--)
        {
            auto start = high_resolution_clock::now();
            solve();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            cout << "Execution time: " << duration.count() << " microseconds" << endl;
        }
        return 0;
    }

    auto start = high_resolution_clock::now();
    solve();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}