#include <atcoder/lazysegtree.hpp>
using namespace atcoder;



struct S {
    int x;
};
struct F {
    int x;
};

/**
 * range incrementation
*/
S op(S l, S r) { return S{std::max(l.x,r.x)}; }
S e() { return S{0}; }
S mapping(F l, S r) { return S{l.x+r.x}; }
F composition(F l, F r) { return F{l.x+r.x}; }
F id() { return F{0}; }

using seg = lazy_segtree<S, op, e, F, mapping, composition, id>;

