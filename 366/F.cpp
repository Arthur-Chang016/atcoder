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

int n, k;

pair<int, int> arr[200005];
long dp[200005][10];

long rec(int ind, int left) {
    if(ind >= n) return 1;
    if(left == 0) return 1;
    long &ret = dp[ind][left];
    if(ret != -1) return ret;
    // not found
    
    auto [a, b] = arr[ind];
    
    int len = n - ind;
    // choose
    long x = rec(ind + 1, left - 1);
    ret = x * a + b;
    
    if(len > left) {
        ret = max(ret, rec(ind + 1, left));
    }
    return ret;
}

int32_t main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr + n, [](const pair<int, int> a, const pair<int, int> b){
        int a1 = a.first, b1 = a.second, a2 = b.first, b2 = b.second;
        return a1 * b2 + b1 > a2 * b1 + b2;
    });
    
    memset(dp, -1, sizeof(dp));
    cout << rec(0, k) << endl;
    
    
    
}
