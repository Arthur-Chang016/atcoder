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
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    vector<unordered_set<int>> S(n);
    for(int i = 0; i < n; ++i) S[i].insert(arr[i]);
    
    
    for(int j = 0; j < q; ++j) {
        int a, b; cin >> a >> b;
        --a, --b;
        
        auto &A = S[a], &B = S[b];
        if(A.size() < B.size()) {
            B.insert(begin(A), end(A));
            A.clear();
        } else {
            A.insert(begin(B), end(B));
            B.clear();
            swap(A, B);
        }
        cout << B.size() << '\n';
    }
    
    
}

