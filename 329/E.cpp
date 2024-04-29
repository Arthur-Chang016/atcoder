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

int n, m;
string s, t;

inline bool findT(int ind) {
    if(n - ind < t.size()) return false;
    for(int i = 0; i < m; ++i) {
        if(t[i] != s[ind + i]) return false;
    }
    return true;
}

inline pair<bool, int> endwithT(int ind) {
    for(int i = 1; i <= 5; ++i) {
        string sub = s.substr(ind, i);
        if(t.ends_with(sub)) return {true, i};
    }
    return {false, 0};
}

char dp[200005][2];

bool rec(int ind, bool newstart) {
    if(ind >= s.size()) return true;
    char &ret = dp[ind][newstart];
    if(ret != -1) return ret;
    // not found
    
    bool fullT = findT(ind);
    if(fullT && (rec(ind + t.size(), true) || rec(ind + t.size(), false))) return ret = true;
    
    if(newstart) {
        for(int len = 1; len <= t.size(); ++len) {
            string sub = s.substr(ind, len);
            if(t.starts_with(sub) && rec(ind + len, true)) return ret = true; 
        }
        return ret = false;
    } else {
        auto [endT, endLen] = endwithT(ind);
        if(endT && (rec(ind + endLen, true) || rec(ind + endLen, false))) return ret = true;
        
        for(int len = 1; len <= t.size(); ++len) {  // 
            string sub = s.substr(ind, len);
            if(t.find(sub) != std::string::npos) { // is mid of t
                if(rec(ind + len, true)) return ret = true;
            }
        }
        return ret = false;
    }
}

bool solve() {
    memset(dp, -1, sizeof(dp));
    bool ans = rec(0, true);
    return ans;
}

int main() {
    cin >> n >> m >> s >> t;
    
    bool ans = true;
    ans &= solve();
    reverse(begin(s), end(s));  // reverse and do it again
    reverse(begin(t), end(t));
    ans &= solve();
    cout << (ans ? "Yes" : "No") << '\n';
}