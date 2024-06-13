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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    
    bool pre = t.starts_with(s);
    bool post = t.ends_with(s);
    
    if(pre && post) cout << 0;
    else if(pre) cout << 1;
    else if(post) cout << 2;
    else cout << 3;
    
    
    
}
