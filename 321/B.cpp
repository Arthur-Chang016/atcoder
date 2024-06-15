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

int a[100];

int32_t main() {
    int n, x;
    cin >> n >> x;
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    for(int j = 0; j <= 100; ++j) {
        
        vector<int> v(a, a + n);
        v.push_back(j);
        
        sort(v.begin(), v.end());
        int sum = 0;
        for(int i = 1; i < v.size() - 1; ++i) sum += v[i];
        
        if(sum >= x) {
            cout << j;
            return 0;
        }
        
        
    }
    cout << -1;
    
    
    // int sum = 0;
    // for(int i = 1; i < n - 1; ++i) {
    //     sum += a[i];
    // }
    
    // int ans = x - sum;
    
    // if(ans < 0 || ans > 100) cout << -1;
    // else cout << ans;
    
    
    
}
