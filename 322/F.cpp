#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

#include <atcoder/lazysegtree.hpp>
using namespace atcoder;

struct S {
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value + b.value, a.size + b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

using seg = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int32_t main() {
    
    
    
    
    
    
}
