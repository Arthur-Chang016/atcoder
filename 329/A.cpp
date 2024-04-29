#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size() - 1; ++i) cout << s[i] << ' ';
    cout << s.back();
}