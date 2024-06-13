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

int arr[200005], ans[200005];

int32_t main() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        arr[tmp - 1] += 1;
    }
    
    // for(int i = 1; i < n; ++i) {
    //     arr[i] += arr[i - 1];
    // }
    
    int next = n - 1;
    for(int i = n - 1; i >= 0; --i) {
        if(arr[i] == 1) next = i;
        ans[i] = next - i;
        
    }
    
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    
    
    // for(int i = 0; i < n; ++i) {
    //     int next = 
        
    // }
    
}
