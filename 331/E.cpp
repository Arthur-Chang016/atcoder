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


int32_t main() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
    
    unordered_map<int, unordered_set<int>> M;  // main -> [sides]
    for(int i = 0; i < l; ++i) {
        int x, y; cin >> x >> y;
        // M[x - 1].push_back(y - 1);
        M[x - 1].insert(y - 1);
    }
    
    vector<pair<int, int>> B(m);
    for(int i = 0; i < m; ++i) B[i] = {b[i], i};
    sort(begin(B), end(B), greater<>());
    
    long ret = 0;
    for(int i = 0; i < n; ++i) {  // ai
        auto &noset = M[i];
        // for(int j = B.size() - 1; j >= 0; --j) {
        //     auto 
        // }
        for(auto [bi, ind]: B) {
            if(noset.count(ind) == 0) {  // good
                ret = max(ret, (long)bi + a[i]);
                break;
            }
        }
        
    }
    cout << ret << '\n';
    
    
}