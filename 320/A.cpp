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
    int a, b;
    cin >> a >> b;
    
    int c = 1, d = 1;
    for(int i = 0; i < a; ++i) c *= b;
    for(int i = 0; i < b; ++i) d *= a;
    
    cout << (c + d);
    
    
    
}
