#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
// inline iterator find_by_order(size_type);
// size_type order_of_key(key_const_reference);

#define long int64_t

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

int n;
pair<int, int> arr[101];

long dp[501][501][101];
long all, part;

long rec(int a, int b, int ind) {
    if(a > part || b > part) return INT_MAX;
    if(ind >= n) {
        if(a == b && all - a - b == b) return 0;
        return INT_MAX;
    }
    long &ret = dp[a][b][ind];
    if(ret != -1) return ret;
    // not found
    
    // int c = all - a - b;
    auto [team, power] = arr[ind];
    
    // to a
    ret = rec(a + power, b, ind + 1) + (team != 1);
    ret = min(ret, rec(a, b + power, ind + 1) + (team != 2));
    ret = min(ret, rec(a, b, ind + 1) + (team != 3));
    return ret;
}

int32_t main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
    
    
    all = 0;
    for(int i = 0; i < n; ++i) {
        all += arr[i].second;
    }
    if(all % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    part = all / 3;
    memset(dp, -1, sizeof(dp));
    
    long ans = rec(0, 0, 0);
    
    if(ans >= INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    
    
}
