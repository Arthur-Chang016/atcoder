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

int main() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    
    vector<int> arr;
    for(int i = 1; i < n; ++i) if(s[i] == s[i - 1]) arr.push_back(i - 1);
    
    for(int j = 0; j < q; ++j) {
        int a, b; cin >> a >> b;
        --a, --b;
        
        int l = lower_bound(begin(arr), end(arr), a) - begin(arr);
        int r = lower_bound(begin(arr), end(arr), b) - begin(arr) - 1;
        
        cout << max(r - l + 1, 0) << '\n';
    }
    
    
}