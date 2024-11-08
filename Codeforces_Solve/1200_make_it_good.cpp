//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a;

    for( int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int flag = 0;

    for(int i = 0; i<n-1; i++){
        if(a[i+1] > a[i]){
            flag++;
            break;
        }
    }
    if( flag == 0 ){
        cout << "0" << endl;
        return;
    }
    for(int i = 0; i<n-1; i++){
        if(a[i+1] < a[i]){
            flag++;
            break;
        }
    }
    if( flag == 1 ){
        cout << "0" << endl;
        return;
    }

    int flag2 = 0;
    int i = n-1;

    while( 1 ){
        if(i <= 1){
            cout << "0" << endl;
            return;
        }
        if( a[i-1] < a[i] && flag2 == 0 ){
            flag2 = 1;
            while( a[i-1] <= a[i] ){
                if(i <= 1){
                    cout << "0" << endl;
                    return;
                }
                i--;
            }
            cout << i << endl;
            return;
        }
        i--;
    }
}

int main()
{
    long long int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
}