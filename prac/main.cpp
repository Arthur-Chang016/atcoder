#include <bits/stdc++.h>
using namespace std;

static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

int h[200001], a[200001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> h[i];
        
    for(int i = 0; i < n; ++i)
        cin >> a[i];
        
    map<int, long> M;  // height, score
    
    for(int i = 0; i < n; ++i) {
        // find the first less
        auto it = M.lower_bound(h[i]), cur = M.end();
        long newsc = 0;
        
        if(it != M.begin()) {
            newsc = prev(it)->second + a[i];
            
            if(it != M.end() && it->second == h[i]) it->second = max(it->second, newsc), cur = it;
            else {
                cur = M.insert({h[i], newsc}).first;
            }
        } else { // the smallest ele
            cur = M.insert({h[i], a[i]}).first;
        }
        
        // make the map monotonic increasing
        for(; cur != M.end(); ) {
            auto ne = next(cur);
            if(ne == M.end()) break;
            else {
                if(ne->second <= cur->second) M.erase(next(cur));
                else break;
            }
            
        }
    }
    cout << M.rbegin()->second;
    
}