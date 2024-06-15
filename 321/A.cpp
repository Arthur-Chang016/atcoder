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
    string s;
    cin >> s;
    
    // cout << s << endl;
    // cout << endl << endl;
    
    for(int i = 1; i < s.size(); ++i) {
        if(s[i - 1] >= s[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    
}
