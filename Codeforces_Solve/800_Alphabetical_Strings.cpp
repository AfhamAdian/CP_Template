#include<iostream>
#include<string>

using namespace std;

void solve()
{
    string s;
        cin >> s;

        int arr[26] = {0};
        int max = -1;

        for(int i = 0;i<s.length(); i++){
            if(arr[s[i]-'a'] >= 1){
                cout << "NO" << endl;
                return;
            }
            if( s[i]-'a' > max ) max = s[i]-'a';
            arr[s[i]-'a']++;
        }
        
        for(int i = 0;i<max; i++){
            if(arr[i] != 1) {
                cout << "NO" << endl;
                return;
            }
        }

        for(int i = 0;i<s.length()-1; i++){
            if(s[i] == 'a'){
                while(s[i+1]){
                    //cout << s[i] << " " ;
                    if(s[i+1] < s[i]){
                        cout << "NO" << endl;
                        return;
                    }
                    i++;
                }
            }
            if(s[i] < s[i+1]) {
                cout << "NO" << endl;
                return;
            }
        }

        cout << "YES" << endl;

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