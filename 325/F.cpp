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

long n, l1, c1, k1, l2, c2, k2;
long d[101];
long dp[101][1001];
const long inf = 1e16;

// return min number of l2
long rec(int ind, int l1s) {
    if(ind >= n) return 0;
    // if(l1s < 0) return inf;
    long &ret = dp[ind][l1s];
    if(ret != -1) return ret;
    // not found
    
    long cur = d[ind];
    ret = inf;
    for(int i = 0; i <= l1s; ++i) {
        long sum1 = l1 * i;
        long left = cur - sum1;
        left = max(left, long(0));
        // determine # of l2 to cover left
        long num = (left + l2 - 1) / l2;
        // if(ind == 0) {
        //     cout << i << ' ' << left << ' ' << rec(ind + 1, l1s - i) << endl;
        // }
        ret = min(ret, num + rec(ind + 1, l1s - i));
        if(left <= 0) break;
    }
    
    
    
    return ret;
}

int32_t main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> d[i];
    cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
    
    memset(dp, -1, sizeof(dp));
    
    // long l2s = rec(0, 3);
    // cout << l2s << endl;
    
    long ret = inf;
    for(int i = 0; i <= k1; ++i) {
        long l2s = rec(0, i);
        // cout << i << ' ' << l2s << endl;
        if(l2s > k2) continue;
        long cost = i * c1 + l2s * c2;
        ret = min(ret, cost);
    }
    if(ret >= inf) cout << -1 << endl;
    else cout << ret << endl;
    
}
