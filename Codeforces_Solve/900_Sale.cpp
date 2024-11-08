//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int n,m,ans = 0;
    cin >> n >> m;
    vector<int> ls;

    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        ls.push_back(temp);
    }

    sort(ls.begin(),ls.end());

    //     for (int i=0;i<n;i++){
    //     cout << ls[i] << " ";
    // }

    for (int i = 0; i<m; i++){
        if(ls[i]>= 0 ) {
            continue;
        }
        ans += ls[i];
    }
    cout << -ans << endl;
}