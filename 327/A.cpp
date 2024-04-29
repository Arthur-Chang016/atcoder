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
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 1; i < s.size(); ++i) {
        char a = s[i - 1], b = s[i];
        if((a == 'a' && b == 'b') || (a == 'b' && b == 'a')) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}