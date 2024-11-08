//#include<iostream>
#include <bits/stdc++.h>
#include<vector>

using namespace std;

void solve ()
{
    int n,count1=0,count2=0,count3=0,count4=0;
    cin >> n;
    vector<int> a;

    for( int i =0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);

        if( temp == 1 ) count1++;
        else if( temp == 2 ) count2++;
        else if( temp == 3 ) count3++;
        else if( temp == 4 ) count4++;
    }

    int ans = 0;
    ans += count4;
    ans += count3;
    if(count3 >= count1) count1 = 0;
    else count1 -= count3;
    //cout << count1 << endl;
    ans += count2/2;
    count2 = count2%2 ;
    
    if(count2 == 1){
        ans += 1;
        if( count1 >= 2) count1 -= 2;
        else count1 = 0;
    }

    //cout << count1 << endl;
    ans += ceil(count1/4.0);

    cout << ans << endl;
}


int main()
{
    long long int t;
    // cin >> t;

    // while(t--)
    // {
        solve();
    //}
}