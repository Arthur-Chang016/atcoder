#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

#include <atcoder/segtree.hpp>
using namespace atcoder;

#define long int64_t

#define B 5
long mod[5] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};

using T = array<long, B>;

T op(T a, T b) {
    T ret;
    for(int i = 0; i < B; ++i) ret[i] = (a[i] + b[i]) % mod[i];
    return ret;
}

T e() {
    T ret;
    for(int i = 0; i < B; ++i) ret[i] = 0;
    return ret;
}

using seg = segtree<T, op, e>;

long pow(long a, long p, long m) {
    if(p == 0) return 1;
    if(p == 1) return a;
    long half = pow(a, p / 2, m);
    if(p % 2 == 1) return half * half % m * a % m;
    else return half * half % m;
}

T findleft(seg &tree, int l, int r, long *XX, int n) {
    T ret, s = tree.prod(l, r + 1);
    for(int i = 0; i < B; ++i) {
        long X = XX[i];
        long m = mod[i];
        long base = pow(X, l, m);
        long sum = s[i] % m;
        sum = (sum * pow(base, m - 2, m)) % m;  // sum /= base
        // sum = (sum * pow(X, n - l - 1, m)) % m;  // make it base as pow(X, n)
        ret[i] = sum;
    }
    return ret;
}

T findright(seg &tree, int l, int r, long *XX, int n) {
    T ret, s = tree.prod(l, r + 1);
    for(int i = 0; i < B; ++i) {
        long X = XX[i];
        long m = mod[i];
        long base = pow(X, n - r - 1, m);
        long sum = s[i] % m;
        sum = (sum * pow(base, m - 2, m)) % m;  // sum /= base
        // sum = (sum * pow(X, r, m)) % m;  // make it base as pow(X, n)
        ret[i] = sum;
    }
    return ret;
}

void print(T t) {
    for(int i = 0; i < B; ++i) cout << t[i] << ' ';
    cout << endl;
}

int32_t main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    long XX[5];
    mt19937_64 rng(time(0));
    for (int i = 0; i < B; i++) XX[i] = rng() % mod[i];
    
    // build seg tree
    seg left(n), right(n);
    for(int i = 0; i < n; ++i) {
        T l, r;
        for(int j = 0; j < B; ++j) l[j] = pow(XX[j], i, mod[j]) * long(s[i]) % mod[j];
        for(int j = 0; j < B; ++j) r[j] = pow(XX[j], n - i - 1, mod[j]) * long(s[i]) % mod[j];
        left.set(i, l);
        right.set(i, r);
    }
    
    auto printall = [&] () {
        for(int i = 0; i < n; ++i) {
            T l = left.get(i), r = right.get(i);
            print(l);
        }
        for(int i = 0; i < n; ++i) {
            T l = left.get(i), r = right.get(i);
            print(r);
        }
    };
    
    for(int i = 0; i < q; ++i) {
        int type; cin >> type;
        if(type == 1) {  // modify
            int x;
            char c; cin >> x >> c;
            --x;
            T l, r;
            for(int j = 0; j < B; ++j) l[j] = pow(XX[j], x, mod[j]) * long(c) % mod[j];
            for(int j = 0; j < B; ++j) r[j] = pow(XX[j], n - x - 1, mod[j]) * long(c) % mod[j];
            left.set(x, l);
            right.set(x, r);
        } else {  // query
            
            int L, R; cin >> L >> R;
            --L, --R;
            if(L == R) { cout << "Yes\n"; continue; }
            int len = R - L + 1;
            
            T leftpart = findleft(left, L, R, XX, n);
            T rightpart = findright(right, L, R, XX, n);
            
            bool same = true;
            for(int j = 0; j < B; ++j) {
                same &= leftpart[j] == rightpart[j];
            }
            cout << (same ? "Yes" : "No") << '\n';
        }
    }
    
}