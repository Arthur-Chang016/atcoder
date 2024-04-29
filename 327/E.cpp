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

int n;
vector<int> arr;

double find_deno(int n) {
    const double r = 0.9, a = 1;
    const double up = a * (pow(r, n) - 1);
    const double low = r - 1;
    return up / low;
}

double dp[5001][5001];

double rec(int ind, int k) {
    if(k == 0) return 0;
    // if(ind >= n) return -(1e15);
    double &ret = dp[ind][k];
    if(ret != DBL_MAX) return ret;
    // not found
    ret = -DBL_MAX;
    
    if(k < n - ind) {
        ret = max(ret, rec(ind + 1, k));  // not choose
    }
    // choose
    int sc = arr[ind];
    const double coeff = pow(0.9, k - 1);  // cur
    
    if(k == 1) {
        ret = max(ret, (double)sc);
    } else {
        double next = rec(ind + 1, k - 1); // with (k - 2)
        int num_of_deno = k - 1;
        double next_low = find_deno(num_of_deno);
        double next_up = next * next_low;
        
        double cur_up = next_up + coeff * sc;
        double cur_low = next_low + coeff;
        
        ret = max(ret, cur_up / cur_low);
    }
    return ret;
}

// double find(int k) {
//     // vector<vector<double>> dp(n, vector<double>(k + 1, DBL_MAX));
//     for(int i = 0; i < n; ++i) for(int j = 0; j <= k; ++j) dp[i][j] = DBL_MAX;
    
//     double ans = rec(0, k);
//     double con = double(1200) / sqrt(k);
//     return ans - con;
// }

int32_t main() {
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // init dp
    for(int i = 0; i < n; ++i) for(int j = 0; j <= n; ++j) dp[i][j] = DBL_MAX;
    
    double ans = -DBL_MAX;
    for(int i = 1; i <= n; ++i) {
        double ret = rec(0, i);
        double con = double(1200) / sqrt(i);
        ans = max(ans, ret - con);
    }
    cout << fixed << setprecision(10) << ans <<endl;
}
