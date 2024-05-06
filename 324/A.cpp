#include <bits/stdc++.h>
using namespace std;

#define long int64_t

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();


int32_t main() {
    int n;
    cin >> n;
    int prev = -1, cur;
    for(int i = 0; i < n; ++i) {
        cin >> cur;
        if(prev != -1) {
            if(prev != cur) {
                cout << "No" << endl;
                return 0;
            }
            // prev = cur;
        }
        prev = cur;
    }
    
    cout << "Yes" << endl;
    
    
}
