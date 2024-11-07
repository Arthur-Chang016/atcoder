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


int mat[102][102][102];
int n;

int32_t main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k) {
                int cur; cin >> cur;
                cur = cur + mat[i - 1][j][k] + mat[i][j - 1][k] + mat[i][j][k - 1];
                cur = cur - mat[i - 1][j - 1][k] - mat[i][j - 1][k - 1] - mat[i - 1][j][k - 1];
                cur = cur + mat[i - 1][j - 1][k - 1];
                mat[i][j][k] = cur;
            }
    }
    
    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        
        int ret = mat[rx][ry][rz];
        ret = ret - mat[lx - 1][ry][rz] - mat[rx][ly - 1][rz] - mat[rx][ry][lz - 1];
        ret = ret + mat[lx - 1][ly - 1][rz] + mat[rx][ly - 1][lz - 1] + mat[lx - 1][ry][lz - 1];
        ret = ret - mat[lx - 1][ly - 1][lz - 1];
        
        cout << ret << '\n';
    }
    
    // cout << mat[2][2][2] << endl;
    
    
    // sum
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j)
    //         for(int k = 0; k < n; ++k)
    //             cin >> mat[i][j][k];
    // }
    
    
    
}
