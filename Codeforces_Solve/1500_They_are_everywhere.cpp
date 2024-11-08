// #include <bits/stdc++.h>

// using namespace std;

// #define FOR(i, a, b) for (ll i=a; i<(b); i++)
// #define F0R(i, a) for (ll i=0; i<(a); i++)
// #define trav(a,x) for (auto& a : x)

// #define sz(x) (int)(x).size()
// #define mp make_pair
// #define pb push_back
// // #define f first
// // #define s second
// #define lb lower_bound
// #define ub upper_bound
// //#define all(x) x.begin(), x.end()
// #define ins insert

// // #define all(x) (x).begin(), (x).end()
// // #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

// #define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define ll long long int
// // #define vi vector<int>
// // #define vll vector<ll>

// #define cinall(v,n) {for( ll i = 0 ; i<n; i++){ ll t; cin >> t; v.pb(t); }}
// #define coutall(v,n) {for( ll i = 0 ; i<n; i++){ cout <<  v[i] << " "; } cout <<  endl; }

// #define pp(ans)  //cout <<  ans << endl
// #define yes cout<<"YES\n"
// #define no   cout<<"NO\n"



//     // -Examine Test Cases
//     // -Analyze why it is behaving that way
//     // -Come with a Hypothesis
//     // -Disprove the Hypothesis
    
//     // -Prepare a code outline
//     // -check if the code outline validates the test cases
//     // -code
//     // -think of corner case before submitting 


// void solve()
// {
//     ll n;   
//     cin >> n;
    
//     string str;     
//     cin >> str;

//     string check = "";
//     int arrS[26] = {0};
//     int arrB[26] = {0};

//     for( int i = 0; i<str.length(); i++)
//     {
//         if( str[i] >= 'a' && str[i] <= 'z' ){
//             arrS[str[i]-'a']++;
//         }
//         else{
//             arrB[str[i]-'A']++;
//         }
//     }
    
//     for( int i = 0; i<26; i++ )
//     {
//         if( arrS[i] > 0 ){
//             check += (char)(i+'a');
//         }
//         else if ( arrB[i] > 0 ){
//             check += (char)('A'+i);
//         }
//     }
    
//     unordered_map<char,int> mp;

//     auto f = [&]() -> bool{
//         for( int i = 0; i<check.length(); i++ )
//         {
//             if( mp[check[i]] == 0 )
//                 return false;
//         }
//         return true;
//     };

//     ll i = 0,j = 0;
//     ll count = INT32_MAX;

//     mp[str[0]]++;
//     if( f() ){
//         cout << "1" << endl;
//         return;
//     }
//     ll prev;

//     while( i<=j && j<n )
//     {
//        prev = i;
//        while( i<=j )
//        {
//             if( j == n-1 ){
//                 break;
//             }

//             j++;
//             mp[str[j]]++;

//             if( f() )
//             {
//                 count = min(count,j-i+1);
//                 break;
//             }
//        }

//        while( i<=j )
//        {
//             if( f() ){
//                 count = min(count,j-i+1);
//                 mp[str[i]]--;
//                 i++;
//             }
//             else{
//                 break;
//             }
//        }

//        if( i ==  prev ){
//             i++;
//        }
//     }

//     cout << count << endl;

// }

// int main()
// {
//     fast_io;
//     bool multi = true;
//     // bool multi = false;

//     if (multi) {
//         ll t;
//         cin >> t;
//         while (t--) solve();
//         return 0;
//     }

//     solve();

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

// Function to compute nCr (combinations)
long long combination(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    vector<int> cards(10);
    for (int i = 0; i < 10; ++i) {
        cin >> cards[i];
    }

    int K;
    cin >> K;

    // If K is greater than the number of distinct cards available, output 0
    int availableDistinct = 0;
    for (int i = 0; i < 10; ++i) {
        if (cards[i] > 0) {
            availableDistinct++;
        }
    }
    if (availableDistinct < K) {
        cout << 0 << endl;
        return 0;
    }

    long long result = 0;
    
    vector<int> indices(10, 0);
    for (int i = 0; i < K; ++i) {
        indices[i] = 1;  // Choose K elements
    }

    do {
        long long ways = 1;
        for (int i = 0; i < 10; ++i) {
            if (indices[i] == 1) {
                ways *= combination(cards[i], 1);  // Choose 1 card from available cards[i]
            }
        }
        result += ways;
    } while (prev_permutation(indices.begin(), indices.end()));

    cout << result << endl;

    return 0;
}
