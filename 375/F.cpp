#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
// inline iterator find_by_order(size_type);
// size_type order_of_key(key_const_reference);

#define long int64_t

#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

// -------------------------

int n, m, q;

long mat[301][301];

int32_t main() {
    cin >> n >> m >> q;
    vector<array<int, 3>> edges(m);
    for(auto &[a, b, c]: edges) {
        int d, e, f; cin >> d >> e >> f;
        a = d - 1, b = e - 1, c = f;
    }
    vector<vector<int>> qs;
    unordered_set<int> closed;
    
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) mat[i][j] = 1e16;
    
    // memset(mat, 0x7f, sizeof(mat));
    for(int i = 0; i < q; ++i) {
        int type, a, b; cin >> type;
        if(type == 1) cin >> a, qs.push_back({type, a - 1}), closed.insert(a - 1);
        else cin >> a >> b, qs.push_back({type, a - 1, b - 1});
    }
    // init mat
    for(int i = 0; i < n; ++i) mat[i][i] = 0;
    for(int i = 0; i < m; ++i) {
        if(closed.contains(i)) continue;
        auto [a, b, c] = edges[i];
        mat[a][b] = mat[b][a] = c;
    }
    
    for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        // if(mat[i][k] + mat[k][j] < mat[i][j])
            mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    }
    
    // cout << "here" << q << endl;
    
    vector<long> ans;
    long inf = 0x3f3f3f3f3f3f3f3f;
    for(int i = q - 1; i >= 0; --i) {
        // cout << "here" << endl;
        
        // cout << qs[i].size() << endl;
        
        int type = qs[i][0];
        if(type == 1) {  // add road
            int r = qs[i][1];
            auto [a, b, c] = edges[r];
            // cout << r << endl;
            
            // cout << a << ' ' << b << ' ' << c << endl;
            
            if((long)c < mat[a][b]) {
                mat[a][b] = mat[b][a] = c;
                
                for(int k = 0; k < n; ++k) for(int l = 0; l < n; ++l) {
                    mat[k][l] = min({mat[k][l], mat[k][a] + mat[a][b] + mat[b][l], mat[k][b] + mat[b][a] + mat[a][l]});
                    
                    // if(mat[k][a] + mat[a][b] + mat[b][l] < mat[k][l])
                    //     mat[k][l] = mat[k][l] = mat[k][a] + mat[a][b] + mat[b][l];
                    // if(mat[k][l] > mat[k][b] + mat[b][a] + mat[a][l])
                    //     mat[l][k] = mat[k][l] = mat[k][b] + mat[b][a] + mat[a][l];
                }
            }
            
        } else {
            int a = qs[i][1], b = qs[i][2];
            
            // cout << a << ' ' << b << endl;
            // cout << mat[a][b] << '\n';
            ans.push_back(mat[a][b]);
        }
        
    }
    
    reverse(ans.begin(), ans.end());
    for(long i: ans) {
        if(i >= 1e16) cout << -1 << endl;
        else cout << i << '\n';
    }
    
    
}
