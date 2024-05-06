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

class E {
public:
    int t, b, c;
};

int n, m;

vector<E> g[200005];

pair<long, long> dp[200005];

// beauty, cost
pair<long, long> rec(int root) {
    if(root == n - 1) return {0, 0};
    pair<long, long> &ret = dp[root];
    if(ret.first != -1) return ret;
    // not found
    
    auto &nexts = g[root];
    if(nexts.empty()) return ret = {0, 1e15};
    
    double best = -1;
    long sumb, sumc;
    for(auto [next, b, c]: nexts) {
        auto [bea, cost] = rec(next);
        long tmpb = bea + b, tmpc = cost + c;
        if(double(tmpb) / tmpc > best) best = double(tmpb) / tmpc, sumb = tmpb, sumc = tmpc;
    }
    return ret = {sumb, sumc};
}

int32_t main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int tar, t, b, c; cin >> tar >> t >> b >> c;
        --t; --tar;
        g[tar].push_back({t, b, c});
    }
    
    memset(dp, -1, sizeof(dp));
    
    
    pair<long, long> ret = rec(0);
    double ans = double(ret.first) / ret.second;
    
    cout << setprecision(20) << ans << endl;
    
    
}
