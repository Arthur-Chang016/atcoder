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

// bool vis[200005];
bool B[200005];



int32_t main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> SS(m), T(m);
    
    for(int i = 0; i < m; ++i) {
        int a; cin >> a;
        SS[i] = --a;
    }
    for(int i = 0; i < m; ++i) {
        int a; cin >> a;
        T[i] = --a;
    }
    
    for(int i = 0; i < m; ++i) {
        int a = SS[i], b = T[i];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    // cout << "here" << endl;
    
    unordered_set<int> S;
    for(int i = 0; i < n; ++i) S.insert(i);
    
    while(!S.empty()) {
        auto f = S.begin(); 
        int root = *f;
        // S.erase(f);
        
        // see if bipartite
        queue<pair<int, bool>> q;
        q.push({root, false});
        // vis[0] = true;
        S.erase(root);
        while(!q.empty()) {
            auto [cur, b] = q.front(); q.pop();
            
            for(int next: g[cur]) {
                // if(vis[next]) continue;
                // if(vis[next]) {
                if(S.count(next) == 0) {
                    if(B[next] == b) {
                        cout << "No\n";
                        return 0;
                    }
                    continue;
                }
                // vis[next] = true;
                // S.erase(S.find(next));
                S.erase(next);
                B[next] = !b;
                q.push({next, !b});
            }
        }
        
    }
    
    
    
    cout << "Yes\n";
    return 0;
    
    
}