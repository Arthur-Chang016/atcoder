#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

int n, arr[200005], q;

inline int find_first(pbds &M) {
    int l = 0, r = M.size();
    
    while(l < r) {
        int mid = l + (r - l) / 2;
        auto [num, cnt] = *M.find_by_order(mid);
        if(mid == num) l = mid + 1;
        else r = mid;
    }
    return l;
}

void print(pbds &M) {
    for(auto [a, b]: M) cout << a << ' ' << b << endl; cout << endl;
}

int main() {
    cin >> n >> q;
    // unordered_multiset<int> S;
    pbds M;  // int -> int
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        // M.insert({tmp});
        M[tmp]++;
    }
    
    // print(M);
    
    for(int i = 0; i < q; ++i) {
        int j, x;
        cin >> j >> x;
        int orig = arr[j - 1];
        
        // modify M
        if(auto it = M.find(orig); it != M.end()) {
            if(it->second == 1) M.erase(it);
            else --it->second;
        }
        M[x]++;
        
        // print(M);
        
        int ret = find_first(M);
        
        // find the first 
        
        // M.erase(M.find(orig));
        // M.insert(x);
        arr[j - 1] = x;
        cout << ret << '\n';
    }
    
    
}