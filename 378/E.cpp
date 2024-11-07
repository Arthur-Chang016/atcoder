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

long n, m;
long arr[200005];

int32_t main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= n; ++i) arr[i] = (arr[i] + arr[i - 1]) % m;
    
    rbtree tree;
    
    long suml = 0, ret = 0;
    for(int r = 1; r <= n; ++r) {
        long Sr = arr[r];
        
        // find how many S(l - 1) > S(r)
        long Xr = tree.size() - tree.order_of_key({arr[r], INT_MAX});
        
        ret += Sr * r - suml + m * Xr;
        
        // update tree
        tree.insert({arr[r], r});
        suml += arr[r];
    }
    cout << ret << endl;
}
