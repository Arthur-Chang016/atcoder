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

long n, a, b, c;

vector<pair<long, long>> g[20005];

int32_t main() {
    cin >> n >> a >> b >> c;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            long d;
            cin >> d;
            long comp = d * a, train = d * b + c;
            
            g[i].push_back({j, comp});
            g[i + n].push_back({j + n, train});
        }
        g[i].push_back({i + n, 0});
    }
    
    const long MAX = 1e15;
    vector<long> d(n * 2, MAX);
    vector<bool> u(n * 2, false);
    
    d[0] = 0;
    for(int i = 0; i < 2 * n; ++i) {
        long v = -1;
        for(int j = 0; j < 2 * n; ++j) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == MAX)
            break;
        u[v] = true;
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
            }
        }
    }
    
    long ans = d[n * 2 - 1];
    cout << ans << endl;
}
