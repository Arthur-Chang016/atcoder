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

const long mod = 998244353;

long pow(long a, long b) {
    if(b == 0) return 1;
    long h = pow(a, b / 2);
    if(b % 2 == 1) return h * h % mod * a % mod;
    else return h * h % mod;
}

long div(long a) {
    return pow(a, mod - 2);
}

int32_t main() {
    
    // 7 / 27
    
    // long ans = 7 * div(27) % mod;
    // cout << ans << endl;
    
    // long tmp = 369720131LL * 27 % mod;
    
    // cout << tmp << endl;
    
    
    
    
    
}

