#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
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
// #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int

#define cinall(v,n) {for( int i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
#define coutall(v,n) {for( int i = 0 ; i<n; i++){ //cout <<  v[i] << " "; } //cout <<  endl; }

#define pp(ans)  //cout <<  ans << endl
#define yes cout<<"YES\n"
#define no   cout<<"NO\n"




#include<bits/stdc++.h>

using namespace std;

#define available 1
#define notAvailable -1

void solve ()
{
    int n;
    cin >> n;


    vector<int> AnsArr;
    stack<int> DataStack;
    priority_queue<int> DataPq;
    int DataToAvailabilityMap[n] = {available};


    for( int i = 0; i<n; i++)
    {
        int t;
        cin >> t;
        DataStack.push(t);
        DataPq.push(t);
        DataToAvailabilityMap[t-1] = available;
    }

    while( !DataStack.empty() )
    {
        while( DataToAvailabilityMap[DataPq.top()-1] == notAvailable )
        {
            DataPq.pop();
        }
        int max = DataPq.top();
        DataPq.pop();

        stack<int> tempStack;

        while( DataStack.top() != max )
        {
            DataToAvailabilityMap[DataStack.top()-1] = notAvailable;
            tempStack.push(DataStack.top());
            DataStack.pop();
        }
        
        DataToAvailabilityMap[DataStack.top()-1] = notAvailable;
        tempStack.push(DataStack.top());
        DataStack.pop();

        while( !tempStack.empty() )
        {
            AnsArr.push_back(tempStack.top());
            tempStack.pop();
        }
    }

    for( int i = 0; i<AnsArr.size(); i++)
    {
        cout << AnsArr[i] << " ";
    }
    cout << endl;

}

int main()
{
    fast_io;
    bool multi = true;
    // bool multi = false;

    if( multi ){
        ll t;
        cin >> t;
        //cout << t << endl;
        while(t--) solve();
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