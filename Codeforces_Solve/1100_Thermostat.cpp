//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
   long long int l,r,a,b,x,max,min;
   cin >> l >> r >> x;
   cin >> a >> b;
   int ans= 999;

   if(a==b){
    cout << "0" << endl;
    return;
   }

   if( abs(a-b)>= x) {
    cout << "1" << endl;
    return;
   }

    if( a-l >=x && b-l>= x ) cout << "2" << endl;
    else if( r-a >= x && r-b >= x ) cout << "2" << endl;
    else if( a-l >=x && b-l < x ) {
        if( r-b >=x) cout << "3" << endl;
    }
    else if( r-a >= x && r-b < x ){
        if( b-l >= x) cout << "3" << endl;
    }
    else cout << "-1" << endl;

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