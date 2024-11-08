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

// -Examine Test Cases
// -Analyze why it is behaving that way
// -Come with a Hypothesis
// -Disprove the Hypothesis

// -Prepare a code outline
// -check if the code outline validates the test cases
// -code
// -think of corner case before submitting

ll n;
vector<ll> dist(n, LLONG_MAX);
void dijkstra(ll start, ll n, vector<vector<pair<ll, ll>>> &adj)
{
    priority_queue<pair<ll,ll>> pq;
    
    dist[start] = 0;
    pq.push({0, start});

    while( !pq.empty() ){
        ll vertex = pq.top().second;
        ll weight = pq.top().first;
        pq.pop();

        if( weight > dist[vertex] ) continue;
        for( auto edges : adj[vertex] )
        {
            ll to = edges.first;
            ll len = edges.second;

            if( dist[vertex] + len < dist[to] ){
                dist[to] = dist[vertex] + len;
                pq.push({dist[to], to});
            }
        }
    }


}

void solve(ll t)
{
    vector<ll> v;
    for( int i = 0; i<3; i++)
    {
        ll y;
        cin >> y;
        v.pb(y);    

    }

    sort( v.begin(), v.end() );
    ll win = 0;
    ll draw = 0;

    for( int i = 0; i<3; i++)
    {
        win += v[i]/3;
        draw += v[i]%3;
    }

    if( draw%2 == 1){
        cout << "Case " << t << ": invalidum" << endl;
        return;
    }
    draw = draw/2;

    if( win == 3 && draw == 0){
        cout << "Case " << t << ": perfectus" << endl;
        return;
    }
    if( win == 2 && draw == 1){
        cout << "Case " << t << ": perfectus" << endl;
        return;
    }
    if( win == 1 && draw == 2){
        cout << "Case " << t << ": perfectus" << endl;
        return;
    }
    if( win == 0 && draw == 3){
        cout << "Case " << t <<  ": perfectus" << endl;
        return;
    }
    cout << "Case " <<  t << ": invalidum" << endl;
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
        for( int i = 1; i<=t; i++)
        {
            solve(i);
        }
        return 0;
    }

    // solve();

    return 0;
}

