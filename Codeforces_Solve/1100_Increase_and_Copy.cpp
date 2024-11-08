//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
   long long int ans= 0,n,rt,lft = 0;
   cin >> n;

   rt = sqrt(n);
   
   //ans += (n-1);
   lft = n/rt;

   if( lft*rt == n ){
      ans += ((lft-1)+(rt-1));
   }
   else ans += ((lft-1)+rt);

   cout << ans << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
}