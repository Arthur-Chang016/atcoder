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

int q, k;
const long mod = 998244353;

long dp[5001];

void Add(int x) {
    // for(int i = 1; i <= k; ++i) {
    for(int i = k; i >= 1; --i) {
        long add = i - x >= 0 ? dp[i - x] : 0;
        dp[i] = (dp[i] + add) % mod;
    }
}

void Sub(int x) {
    // for(int i = k; i >= 1; --i) {
    for(int i = 1; i <= k; ++i) {
        long sub = i - x >= 0 ? dp[i - x] : 0;
        dp[i] = (dp[i] - sub + mod) % mod;
    }
}


int32_t main() {
    dp[0] = 1;
    
    cin >> q >> k;
    for(int i = 0; i < q; ++i) {
        int x;
        char type;
        cin >> type >> x;
        if(type == '+') {
            Add(x);
        } else {
            Sub(x);
        }
        
        cout << dp[k] << '\n';
        
    }
    
    
    
}
