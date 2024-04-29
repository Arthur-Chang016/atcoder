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

#define N 200005
int tree[N * 2];

int q(int l, int r) {
    l += N; r += N;
    int ret = tree[l];
    while(l <= r) {
        if(l % 2 == 1) ret = max(ret, tree[l++]);
        if(r % 2 == 0) ret = max(ret, tree[r--]);
        l /= 2, r /= 2;
    }
    return ret;
}

void mod(int i, int k) {
    i += N;
    tree[i] += k;
    for(i /= 2; i >= 1; i /= 2)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int32_t main() {
    int n, m; cin >> n >> m;
    
    vector<int> vote(n, 0);
    map<int, set<int>> M;  // vote num -> cans
    for(int i = 0; i < n; ++i) M[0].insert(i);
    
    for(int i = 0; i < m; ++i) {
        int v; cin >> v;
        --v;
        
        int orig = vote[v];
        M[orig].erase(v);
        if(M[orig].empty()) M.erase(orig);
        
        vote[v]++;
        M[orig + 1].insert(v);
        
        // find
        cout << *(M.rbegin()->second.begin()) + 1 << '\n';
    }
    
}

