#include<iostream>
using namespace std;

void solve (){
    long long int n,k;
    cin >> n >> k;

    long long int ans = n/k;
    if( n-ans*k <= k/2) cout << n << endl;
    else{
        cout << ans*k+k/2 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (/* condition */t--)
    {
        /* code */solve();
    }
    
}