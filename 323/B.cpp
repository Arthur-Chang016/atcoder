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


int32_t main() {
    int n; cin >> n;
    vector<string> arr(n);
    
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    
    
    vector<pair<int, int>> ret;
    
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(char c: arr[i]) {
            if(c == 'o') ++cnt;
        }
        ret.push_back({cnt, i});
        
    }
    
    sort(begin(ret), end(ret), [](const auto &a, const auto &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    
    for(auto [a, b]: ret) {
        cout << (b + 1) << '\n';
    }
    
    
}
