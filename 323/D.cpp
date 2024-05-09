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
int S[100001], C[100001];

int32_t main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> S[i] >> C[i];
    }
    
    map<long, long> m;
    
    for(int i = 0; i < n; ++i) {
        m[S[i]] = C[i];
    }
    
    long cur = 0;
    
    // always find the next greater
    while(true) {
        auto f = m.upper_bound(cur);
        if(f == m.end()) break;
        
        auto [s, cnt] = *f;
        if(cnt > 1) {
            if(cnt % 2 == 0) m[s * 2] += cnt / 2, m.erase(f);
            else m[s * 2] += cnt / 2;
        }
        
        cur = s;
    }
    
    cout << m.size() << endl;
    
    
}
