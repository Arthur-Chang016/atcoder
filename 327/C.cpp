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

unordered_set<int> row[9], col[9], block[9];

int32_t main() {
    int n = 9;
    
    
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int a; cin >> a;
            row[i].insert(a);
            col[j].insert(a);
            int ind = 3 * (i / 3) + (j / 3);
            block[ind].insert(a);
        }
    }
    
    for(int i = 0; i < n; ++i) {
        if(row[i].size() != 9) {
            cout << "No\n";
            return 0;
        }
        if(col[i].size() != 9) {
            cout << "No\n";
            return 0;
        }
        if(block[i].size() != 9) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
    
}