//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    int n;
    cin >> n;

    vector<int> list;

    for(int i = 0; i<n; i++)
    {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

    int odd = 0,even = 0,pair = 0;

    for(int i = 0; i<n; i++)
    {
        if(list[i]%2 == 0) even++;
        else odd++;
    }

    if( odd == 0 || even == 0){
        cout << "YES" << endl;
        return;
    }

    if( odd%2 == 0 && even%2 == 0){
        cout << "YES" << endl;
        return;
    }

    if( odd%2 !=0 && even%2 !=0 ){
        sort(list.begin(),list.end());

        for(int i = 0; i<n-1; i++)
        {
            if(list[i]+1 == list[i+1]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
}