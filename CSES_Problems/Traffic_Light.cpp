#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;
    
    set<int> lights;  // to store the positions of the traffic lights
    multiset<int> segments;  // to store the lengths of segments
    
    lights.insert(0);  // starting boundary
    lights.insert(x);  // ending boundary
    segments.insert(x);  // initial segment length

    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        
        // Locate the positions of lights immediately to the left and right
        auto it_right = lights.upper_bound(pos);
        auto it_left = prev(it_right);
        
        // Remove the old segment length
        segments.erase(segments.find(*it_right - *it_left));
        
        // Insert the new segments created by adding this light
        segments.insert(pos - *it_left);
        segments.insert(*it_right - pos);
        
        // Add the new light position to the set
        lights.insert(pos);
        
        // The largest segment length is the last element in the multiset
        cout << *segments.rbegin() << " ";
    }

    cout << endl;
    return 0;
}
