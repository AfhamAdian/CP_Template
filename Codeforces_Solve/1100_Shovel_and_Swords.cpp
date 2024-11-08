//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    long long int  a,b,max,min,ans = 0;
    cin >> a >> b;

    if( a==0 || b==0 ){
        cout << "0" << endl;
        return;
    }

    //if(a!=b){
        if( a>b && a>= 2*b){
            cout << b << endl;
            return;
        }
        else if( a<b && b >= 2*a){
            cout << a << endl;
            return;
        }  
        
        ans = abs(a-b);
        long long int temp = a>b?b:a;
        temp = temp - ans;
        //cout << temp << endl;

        if( temp%3 == 2 ){
            cout << ans+(temp/3)*2+1 << endl;
            return;
        }
        else{
            cout << ans+(temp/3)*2 << endl;
            return;
        }
   // }
    
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