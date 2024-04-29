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

pair<int, long> v[200005];

pair<int, long> find(int i) {
    if(v[i].first == i) {
        return {i, 0};
    } else {
        long sub_sum = v[i].second;
        auto [p, sum] = find(v[i].first);
        return v[i] = {p, sub_sum + sum};
    }
}

void print(pair<int, long> p) {
    cout << p.first << ' ' << p.second << endl;
}

int32_t main() {
    int n, q; cin >> n >> q;
    
    vector<int> ret;
    for(int i = 0; i < n; ++i) v[i] = {i, 0};
    
    for(int i = 0; i < q; ++i) {
        long d;
        int a, b; cin >> a >> b >> d;
        --a, --b;
        auto [pa, suma] = find(a);
        auto [pb, sumb] = find(b);
        if(pa == pb) {
            if(suma - sumb == d) ret.push_back(i + 1);
        } else {  // try to connect it
            v[pa] = {pb, sumb - suma + d};
            ret.push_back(i + 1);
        }
    }
    for(int i: ret) cout << i << ' ';
    cout << endl;
    
}