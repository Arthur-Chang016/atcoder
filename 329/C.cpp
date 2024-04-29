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
    int n;
    string s; cin >> n >> s;
    
    // cout << s << endl;
    
    // unordered_set<char> S;
    unordered_map<char, int> M;  // char -> max len
    int j = 1;
    // long no = 0;
    for(int i = 0; i < n; ) {
        
        while(j < n && s[j] == s[j - 1]) {
            ++j;
        }
        char cur = s[i];
        M[cur] = max(M[cur], j - i);
        
        i = j;
        j++;
        // cout << i << endl;
    }
    
    long ret = 0;
    for(auto [c, cnt]: M) ret += cnt;
    cout << ret << '\n';    
    
}

