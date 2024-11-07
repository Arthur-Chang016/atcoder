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
    long a, b;
    cin >> a >> b;
    
    long x = (a + b) / 2;
    long y = (a - b) / 2;
    
    cout << x << ' ' << y << endl;
    
    
}
