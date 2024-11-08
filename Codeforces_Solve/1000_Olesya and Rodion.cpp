//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    string s;

    if(k != 10){
        //char c = k;
        //cout << "Asd" << "   " << c << endl;
        for( int i=0; i<n ; i++ ){
            s+= to_string(k);
        }
    }
    else {
        if( n == 1){
            cout << "-1" << endl;
            return 0;
        }
       for( int i=0; i<n-1 ; i++ ){
            s+="1";
        } 
        s+="0";
    }
    cout << s << endl;
}