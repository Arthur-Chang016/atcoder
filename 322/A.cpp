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
    string s;
    cin >> n >> s;
    
    for(int i = 0; i < n - 2; ++i) {
        if(s.substr(i, 3) == "ABC") {
            cout << (i + 1) << endl;
            return 0;
        }
        
        
    }
    cout << -1 << endl;
    
}
