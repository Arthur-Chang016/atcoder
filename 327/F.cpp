#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

#include <atcoder/lazysegtree.hpp>
using namespace atcoder;

#define long int64_t


struct S {
    int x;
};
struct F {
    int x;
};
S op(S l, S r) { return S{max(l.x,r.x)}; }
S e() { return S{0}; }
S mapping(F l, S r) { return S{l.x+r.x}; }
F composition(F l, F r) { return F{l.x+r.x}; }
F id() { return F{0}; }

using seg = lazy_segtree<S, op, e, F, mapping, composition, id>;

int n, d, w;
pair<int, int> arr[200005];

int32_t main() {
    cin >> n >> d >> w;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    map<int, vector<int>> M;  // X, -> Ys
    for(int i = 0; i < n; ++i) {
        auto [a, b] = arr[i];  // d, w
        M[a].push_back(b);
    }
    
    seg S(400010);
    long ret = 1;
    auto l = M.begin(), r = l;
    for(; l != M.end(); ++l) {
        // update seg tree
        while(r != M.end() && r->first - l->first + 1 <= d) {  
            for(int y: r->second) {
                S.apply(y, y + w, F{1});
            }
            ++r;
        }
        // find sol
        ret = max(ret, (long)S.prod(0, 200005).x);
        
        // decrease seg tree
        for(int y: l->second) {
            S.apply(y, y + w, F{-1});
        }
    }
    cout << ret << endl;
}
