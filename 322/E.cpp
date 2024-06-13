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

long n, k, p;
long c[101];
vector<long> arr[101];

inline bool check(vector<int> a) {
    for(int i: a) if(i < p) return false;
    return true;
}

long dp[101][7777];

long pow(int a, int b) {
    long ret = 1;
    for(int i = 0; i < b; ++i) ret *= a;
    return ret;
}

long &access(int ind, vector<int> last) {
    long *sub = dp[ind];
    int sub_ind = 0;
    for(int i = 0; i < k; ++i) {
        sub_ind += last[i] * pow(k + 1, i);
    }
    return sub[sub_ind];
}

long rec(vector<int> last, int ind) {
    if(ind >= n) {
        if(check(last)) return 0;
        return 1e15;
    }
    long &ret = access(ind, last);
    if(ret != -1) return ret;
    // not found
    
    // choose or not
    ret = rec(last, ind + 1);
    
    long cost = c[ind];
    for(int i = 0; i < k; ++i) {
        last[i] = min(arr[ind][i] + last[i], p);
    }
    ret = min(ret, cost + rec(last, ind + 1));
    return ret;
}


int32_t main() {
    cin >> n >> k >> p;
    
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        arr[i].resize(k);
        for(int j = 0; j < k; ++j) cin >> arr[i][j];
    }
    
    memset(dp, -1, sizeof(dp));
    
    
    vector<int> last(k, 0);
    long ans = rec(last, 0);
    
    if(ans >= 1e15) cout << -1;
    else cout << ans;
    
    
}
