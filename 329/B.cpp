#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();


int main () {
    int n; cin >> n;
    set<int> S;
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        S.insert(tmp);
    }
    cout << *prev(prev(S.end()));
}