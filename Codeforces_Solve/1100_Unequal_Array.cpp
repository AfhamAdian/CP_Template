//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
   int n;
   cin >> n;
   vector<long long int> a;

   for(int i=0; i<n; i++)
   {
      long long int temp;
      cin >> temp;
      a.push_back(temp);
   }

   int fp = -1,lp = -1,pair = 0;

   for(int i= 0; i<n-1; i++)
   {
      if( a[i] == a[i+1] ){
         if(pair == 0){
            fp = i;
            pair++;
            lp = i+1;
         }
         else {
            pair++;
            lp = i+1;
         }
      }
   }

   if(pair <= 1 ){
      cout << "0" << endl;
      return;
   }

   int no = lp-fp-1;
   if( no <= 2 ) cout << "1" << endl;
   else cout << no-1 << endl;

}


int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
}