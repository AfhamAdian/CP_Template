#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
   string str;
   cin >> str;
   //cout << str << endl;
   vector<int> u,l;

   for( int i = 0; i<str.size(); i++)
   {
      if( str[i] == 'b'){
         if( l.size() != 0)
         {
            l.pop_back();
         }
      }
      else if( str[i] == 'B')
      {
         if(u.size() != 0)
         {
            u.pop_back();
         }
      }
      else if( str[i]>= 'a' && str[i] <= 'z')
      {
         l.push_back(i);
      }
      else if( str[i]>= 'A' && str[i] <= 'Z')
      {
         u.push_back(i);
      }
   }
   int i = 0;
   int j = 0;

   // for( int i = 0; i<u.size(); i++)
   // {
   //    cout << u[i] << " ";
   // }
   // cout << endl;
   // for( int i = 0; i<l.size(); i++)
   // {
   //    cout << l[i] << " ";
   // }
   // cout << endl;

//cout << "Asddwewqewqe" << endl;

   if( u.size() == 0 && l.size() == 0)
   {
      cout << endl;
      return;
   }
   else if( u.size() == 0)
   {
      for( int i = 0; i<l.size(); i++)
      {
         cout << str[l[i]];
      }
      cout << endl;
      return;
   }
   else if( l.size() == 0)
   {
      for( int i = 0; i<u.size(); i++)
      {
         cout << str[u[i]];
      }
      cout << endl;
      return;
   }

   while(1)
   {
      //cout << 'd';
      if( u[i] > l[j] && (i<u.size() && j<l.size()))
      {
         // cout << "i,j :" <<i << " " << j; 
         cout << str[l[j]];
         j++;
         if( j >= l.size() ){
            while(i<u.size()){ cout << str[u[i]]; i++ ;}
            break;
         }
      }
      else if ( u[i] < l[j] && (i<u.size() && j<l.size()) )
      {
         // cout << "2i,j :" <<i << " " << j;
         // cout << "u " << u[i] << endl;
         cout << str[u[i]];
         i++;
         if( i >= u.size() ) {
            while( j<l.size() ){ cout << str[l[j]]; j++; }
            break;
         }
         
      }
      //else cout << "asdsa";
   }
   cout << endl;

  // cout <<endl << "asdsadasdfsafsdfdsf"<< endl;

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