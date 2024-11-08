
#include <bits/stdc++.h>

using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long int

// Function to check if a number is a palindrome in binary
bool is_binary_palindrome(ll num)
{
    string binary = bitset<64>(num).to_string();
    binary = binary.substr(binary.find('1')); // Remove leading zeros
    string rev_binary = binary;
    reverse(rev_binary.begin(), rev_binary.end());
    return binary == rev_binary;
}

// Function to find the M-th base-2 palindrome
ll find_mth_base2_palindrome(ll M)
{
    ll count = 0;
    ll num = 1;
    while (true)
    {
        if (is_binary_palindrome(num))
        {
            count++;
            if (count == M)
            {
                return num;
            }
        }
        num++;
    }
}

int main()
{
    fast_io;
    ll M;
    cin >> M;
    cout << find_mth_base2_palindrome(M) << endl;
    return 0;
}