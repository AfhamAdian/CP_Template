//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    int n,x;
    cin >> n;
    vector<long long int> a;

    for( long long int i = 0; i<n; i++)
    {
        long long int temp;
        cin >> temp;
        a.push_back(temp);
    }

    long long int ans = 0;

    ans += a[0]-1;

    for(long long int i = 0; i<n-1; i++)
    {
        if(a[i]<a[i+1]) ans+= a[i+1] - a[i];
    }

    cout << ans << endl;

  
}


int main()
{
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}