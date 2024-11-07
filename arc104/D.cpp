#include <bits/stdc++.h>
using namespace std;

#define long int64_t

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

int n, k, mod;

int32_t main() {
    cin >> n >> k >> mod;
    
    vector<vector<long>> dp;
    
    int len = (51 * 50) / 2 * 50;
    cout << len << endl;
    vector<long> first(len, 0);
    dp.push_back(first);
    first[0] = 1;
    
    int half = (n + 1) / 2;
    for(int i = 0; i <= half; ++i) {
        auto cur = dp.back();
        for(int j = )
        
    }
    
    
}
