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
    string s, st; cin >> s;
    
    for(char c: s) {
        st += c;
        
        if(st.size() >= 3 && st.ends_with("ABC")) {
            // cout << st << endl;
            st.resize(st.size() - 3);
        }
        
    }
    cout << st << '\n';
    
    
}