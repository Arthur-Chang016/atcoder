#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

int N, S, M, L;
int dp[101];

int rec(int n) {
    if(n <= 0) return 0;
    int &ret = dp[n];
    if(ret != -1) return ret;
    // not found
    return ret = min({S + rec(n - 6), M + rec(n - 8), L + rec(n - 12)});
}

void solve() {
    cin >> N >> S >> M >> L;
    memset(dp, -1, sizeof(dp));
    
    // cout << "ehre" << endl;
    
    int ans = rec(N);
    cout << ans << '\n';
}

int32_t main() {
    int t;
    // cin >> t;
    t = 1;
    for(int i = 0; i < t; ++i) solve();
}