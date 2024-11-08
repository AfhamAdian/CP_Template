#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
   char cell1;
   int cell2;
   cin >> cell1 >> cell2;

   //cout << temp << " " << cell;

   for( int i = 1; i<=8; i++)
   {
      if( i == cell2 ) continue;
      cout << cell1 << i << endl;
   }
   for( int i = 0; i<=7; i++)
   {
      char ans = 'a'+i;
      if( ans  == cell1) continue;
      cout <<  ans << cell2 << endl;
   }
}

int main()
{
   int t;
   cin >> t;
    while(t--)
    {
      solve();
    }

   return 0;
}