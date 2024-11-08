//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    int n,pair = 0,tcount = 0;
    cin >> n;

    string a;
    cin >> a;

    for( int i=0; i<a.length(); i++){
        if(a[i] == 'T') tcount++;
        else if( a[i] == 'M'){
            tcount--;
            pair++;
            if(tcount < 0){
                cout << "NO" << endl;
                return;
            }
        }
    }

    if( tcount == pair && pair == n/3){
        tcount = 0;
        pair = 0;
        for( int i=a.length()-1; i>=0 ; i--){
            if(a[i] == 'T') tcount++;
            else if( a[i] == 'M'){
                tcount--;
                pair++;
                if(tcount < 0){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

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