#include <atcoder/lazysegtree.hpp>
using namespace atcoder;


// 区間加算・区間最小値取得
namespace A {
using S = long long;
using F = long long;
const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

}

// 区間加算・区間最大値取得
namespace B {
using S = long long;
using F = long long;
const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

}

// 区間加算・区間和取得
// 因為需要區間寬度，所以用結構體持有數值。 請用seg.prod(l, r).value取出值。
namespace C {
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

}

// 区間変更・区間最小値取得
namespace D {
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

}

// 区間変更・区間最大値取得
namespace E {
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

}

// 区間変更・区間和取得
namespace F {
struct S{
    long long value;
    int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

}




// struct S {
//     int x;
// };
// struct F {
//     int x;
// };

// /**
//  * range incrementation
// */
// S op(S l, S r) { return S{std::max(l.x,r.x)}; }
// S e() { return S{0}; }
// S mapping(F l, S r) { return S{l.x+r.x}; }
// F composition(F l, F r) { return F{l.x+r.x}; }
// F id() { return F{0}; }

// using seg = lazy_segtree<S, op, e, F, mapping, composition, id>;

