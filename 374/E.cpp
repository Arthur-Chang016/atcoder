#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
// inline iterator find_by_order(size_type);
// size_type order_of_key(key_const_reference);

using ll = long long int;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

// -------------------------

int n, x;
vector<array<int, 4>> arr;

inline bool f(ll w) {  // w: target products
    
    ll sumcost = 0; // sum of budget
    // for(int i = 0; i < n; ++i) {
    //     // s, t
    //     auto [a, p, b, q] = arr[i];
    for(auto [a, p, b, q] : arr) {
        
        // try to find the min cost combination
        ll mincost = 1e15;
        // do s machine
        for(ll s = 0; s <= b; ++s) {
            ll sprod = s * a;
            ll rem = max(w - sprod, 0ll);  // t do it
            ll t = (rem + b - 1) / b;  // rem / b
            mincost = min(mincost, s * p + t * q);
        }
        // do t machine
        for(ll t = 0; t <= a; ++t) {
            ll tprod = t * b;
            ll rem = max(w - tprod, 0ll);
            ll s = (rem + a - 1) / a;
            mincost = min(mincost, s * p + t * q);
        }
        
        sumcost += mincost;
        if(sumcost > x) return false;
    }
    return true;
}

int32_t main() {
    cin >> n >> x;
    arr.resize(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 4; ++j)
            cin >> arr[i][j];
    
    ll l = 1, r = 1e9 + 1;
    while(l < r) {
        long mid = (l + r) / 2;
        
        if(f(mid)) l = mid + 1;
        else r = mid;
    }
    
    cout << (l - 1) << endl;
    
}
