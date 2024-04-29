#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

void solve() {
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;
    
    ++d;
    if(d > D) d = 1, ++m;
    if(m > M) m = 1, ++y;
    cout << y << ' ' << m << ' ' << d << '\n';
    
}

int32_t main() {
    int t;
    // cin >> t;
    t = 1;
    for(int i = 0; i < t; ++i) solve();
}