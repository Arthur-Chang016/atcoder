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
int n, w[1001], x[1001];

int32_t main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> w[i] >> x[i];
    
    long ret = 0;
    for(int t = 0; t < 24; ++t) {
        long sum = 0;
        for(int i = 0; i < n; ++i) {
            int curtime = (x[i] + t) % 24;
            if(9 <= curtime && curtime <= 17) sum += w[i];
        }
        
        ret = max(ret, sum);
    }
    cout << ret << endl;
}
