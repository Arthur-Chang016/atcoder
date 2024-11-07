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



bool check(string_view s) {
    int n = s.size();
    
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}


int32_t main() {
    string s;
    cin >> s;
    
    string_view sv(s);
    int n = sv.size();
    
    // string_view ans;
    int ans = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {  // include
            int len = j - i + 1;
            
            string_view tmp = sv.substr(i, len);
            if(check(tmp) && tmp.size() > ans) {
                ans = tmp.size();
            }
        }
    }
    
    cout << ans;
    
    
}
