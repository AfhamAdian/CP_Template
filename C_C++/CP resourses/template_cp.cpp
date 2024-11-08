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

// #define all(x) (x).begin(), (x).end()
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

// DFS on adjacency list O(V+E)
void dfs(int current_node)
{
    if (visited[current_node])  return;
    visited[current_node] = true;

    for (int neighbor : adj[current_node])  dfs(neighbor);
}


// BFS on adjacency list O(V+E)
void bfs(ll start_node, vector<vector<ll>> &adj, vector<bool> &visited) {
    queue<ll> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int neighbor : adj[current_node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

//dijakstra
vector<ll> dijkstra(ll start_node, vector<vector<pair<ll, ll>>> &adj, ll n) {
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        ll current_node = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_node]) continue;

        for (auto &edge : adj[current_node]) {
            ll neighbor = edge.first;
            ll weight = edge.second;

            if (dist[current_node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[current_node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}



// -Examine Test Cases
// -Analyze why it is behaving that way
// -Come with a Hypothesis
// -Disprove the Hypothesis

// -Prepare a code outline
// -check if the code outline validates the test cases
// -code
// -think of corner case before submitting

//solve function
void solve()
{
    
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