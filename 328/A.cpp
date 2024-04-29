#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

#define long int64_t

int main() {
    int n, x; cin >> n >> x;
    int ret = 0;
    for(int i = 0 ; i < n; ++i) {
        int tmp; cin >> tmp;
        if(tmp <= x) ret += tmp;
    }
    cout << ret  << '\n';
    
    
}