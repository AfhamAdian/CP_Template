//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    long long int a,b,x,y,n,temp = 0;
    cin >> a >> b >> x >> y >> n;

    if(a-x+b-y <= n){
        cout << x*y << endl;
        return;
    }

    // if( a>b ){
    //     if( b-y <= n ){
    //         temp = n-(b-y);
    //         cout << (a-temp)*y;
    //     } 
    //     else cout << a*(b-n) << endl;
    // }

    // else if( a<b ){
    //     if(a-x <= n){
    //         temp = n-(a-x);
    //         cout << x*(b-temp) << endl;
    //     }
    //     else cout << (a-n)*b << endl;
    // }
    // else{
    //     if( x>=y ){
    //         if( b-y <= n){
    //             temp = n-(b-y);
    //             cout << (a-temp)*y << endl;
    //         }
    //         else cout << a*(b-n) << endl;
    //     }
    //     else if( x<y ){
    //         if(a-x <= n){
    //             temp = n-(a-x);
    //             cout << x*(b-temp) << endl;
    //         }
    //         else cout << (a-n)*b << endl;
    //     }
    // }


    long long int ans1,ans2 = 0;

    
    if(a-x <= n)
    {
        temp = n-(a-x);
        ans1 = x*(b-temp);
    } 
    else ans1 = (a-n)*b;

    if( b-y <= n)
    {
        temp = n-(b-y);
        ans2 = (a-temp)*y;
    }
    else ans2 = a*(b-n);

    cout << min(ans1,ans2) << endl;
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