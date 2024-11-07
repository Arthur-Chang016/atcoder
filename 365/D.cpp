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

int n;
string s;

int arr[200005];
int dp[200005][4];

int w(int ao) {
    if(ao == 1) return 2;
    if(ao == 2) return 3;
    if(ao == 3) return 1;
    return -1;
}

// 0: no, 1: R, 2: P, 3: S
int rec(int ind, int last) {
    if(ind >= n) return 0;
    int &ret = dp[ind][last];
    if(ret != -1) return ret;
    // not found
    
    int ao = arr[ind];
    
    int to_win = w(ao);
    
    ret = 0;
    
    if(ao != last) ret = max(ret, rec(ind + 1, ao));
    if(to_win != last) ret = max(ret, 1 + rec(ind + 1, to_win));
    return ret;
}

int32_t main() {
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'P') arr[i] = 2;
        if(s[i] == 'R') arr[i] = 1;
        if(s[i] == 'S') arr[i] = 3;
    }
    
    cout << rec(0, 0) << endl;
    
    
}
