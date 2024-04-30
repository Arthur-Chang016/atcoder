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

int h, w;
string raw[1001];
bool mat[1001][1001];

int inside(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

int v[1000005];

int find(int i) {
    return i == v[i] ? i : v[i] = find(v[i]);
}

int dirs[3] = {0, 1, -1};

int32_t main() {
    cin >> h >> w;
    
    memset(mat, 0, sizeof(mat));
    
    int all = 0;
    for(int i = 0; i < h; ++i) {
        cin >> raw[i];
        for(int j = 0; j < w; ++j)
            if(raw[i][j] == '#') mat[i][j] = true, ++all;
    }
    
    iota(v, v + 1000005, 0);
    // cout << all << endl;
    
    int cnt = 0;
    
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(!mat[i][j]) continue;
            
            // ++cnt;
            
            int ind = i * w + j;
            
            for(int dx: dirs) for(int dy: dirs) {
                int x = i + dx, y = j + dy;
                if(!inside(x, y)) continue;
                if(!mat[x][y]) continue;
                int newind = x * w + y;
                int pa = find(ind), pb = find(newind);
                if(pa != pb) {  // merge
                    // cout << "here" << endl;
                    // ++cnt;
                    
                    v[pa] = pb;
                    --all;
                }
            }
        }
    }
    cout << all << endl;
    
    // cout << "cnt" <<  cnt << endl;
    
}
