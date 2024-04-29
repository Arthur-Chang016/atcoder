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

// bool same(string s) {
//     for(int i = 1; i < s.size(); ++i) if(s[i] != s[0]) return false;
//     return true;
// }

bool same_mon(string m) {
    for(int i = 1; i < m.size(); ++i) if(m[i] != m[0]) return false;
    return true;
}

bool same(string s, char c) {
    for(char cc: s) if(cc != c) return false;
    return true;
}

int main() {
    int n; cin >> n;
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        // string s; cin >> s;
        int d ; cin >> d;
        string m = to_string(i + 1);
        if(same_mon(m) == false) continue;
        
        for(int j = 0; j < d; ++j) {
            string d = to_string(j + 1);
            
            if(same(d, m[0])) {
                // cout << m << ' ' << d << endl;
                ++ret;
            } 
        }
    }
    cout << ret << '\n';
}