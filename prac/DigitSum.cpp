#include <bits/stdc++.h>
using namespace std;

static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

long dp[10001][101][2][2];
#define mod 1000000007
// string s;
char *s;
int D, n;

long rec(int ind, bool tight, int sum, bool start) {
    if(ind >= n) return sum == 0;
    long &ret = dp[ind][sum][tight][start];
    if(ret != -1) return ret;
    // not found
    
    ret = 0;
    for(int i = 0; i < 10; ++i) {
        if(i == 0 && start) continue;
        char c = i + '0';
        if(tight && c > s[ind]) continue;
        
        ret += rec(ind + 1, tight && c == s[ind], (sum + i) % D, 0);
    }
    return ret % mod;
}

int main() {
    string tmp;
    cin >> tmp >> D;
    memset(dp, -1, sizeof(dp));
    s = tmp.data(), n = tmp.size();
    
    long ans = rec(0, 1, 0, 1);
    for(int i = 1; i < n; ++i)
        ans += rec(i, 0, 0, 1);
        ans %= mod;
    
    cout << ans << endl;
    return 0;
}