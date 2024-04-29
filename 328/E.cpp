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

long n, m, k;
vector<array<long, 3>> edges;

long ans = __LONG_LONG_MAX__;

void rec(int mask, int edgecnt, int ind, long sum) {
    
    // if(ind == edges.size()) {
    //     cout << "here" << endl;
    // }
    if(mask == (1 << n) - 1) {
        cout << "here" << endl;
    }
    
    // cout << bitset<10>(mask) << endl;
    if(edgecnt > n - 1) {
        // cout << "here" << endl;
        return ;
    }
    if(mask == (1 << n) - 1 && edgecnt == n - 1) {
        // cout << ind << endl;
        // cout << "here " << ((1 << n) - 1) << endl;
        ans = min(ans, sum % k);
        return;
    }
    if(ind >= edges.size()) return;
    
    
    auto [u, v, cost] = edges[ind];
    // bool U = (mask >> u) & 1, V = (mask >> v) & 1;
    
    rec(mask, edgecnt, ind + 1, sum);
    rec(mask | (1 << u) | (1 << v), edgecnt + 1, ind + 1, sum + cost);
    
    // if(U && V) {
    //     // return;
        
    // } else { // choose or not
    //     rec(mask, edgecnt, ind + 1, sum);
        
    // }
}


int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        edges.push_back({a, b, c});
    }
    
    rec(0, 0, 0, 0);
    cout << ans << endl;
    
    // cout << (9223372036854775807LL % 936294041850197LL) << endl;
    
    // long add = 0;
    // for(auto [a, b, c]: edges) add += c;
    // cout << add % k << endl;
    
    // cout << bitset<10>((1 << n) - 1) << endl;
    
    
}