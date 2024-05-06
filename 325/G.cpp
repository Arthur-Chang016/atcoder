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

string input;
char *s;
int k, n;
int dp[305][305];

// min tree
class seg_tree {
public:
    #define N 305
    int tree[N * 2];
    
    seg_tree() {
        memset(tree, 0, sizeof(tree));
    }
    
    int q(int l, int r) {
        l += N, r += N;
        int ret = tree[l];
        while(l <= r) {
            if(l % 2 == 1) ret = min(ret, tree[l++]);
            if(r % 2 == 0) ret = min(ret, tree[r--]);
            l /= 2, r /= 2;
        }
        return ret;
    }
    
    void mod(int i, int k) {
        i += N;
        tree[i] = k;
        for(i /= 2; i >= 1; i /= 2)
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
    #undef N
};

int32_t main() {
    cin >> input >> k;
    n = input.size();
    s = input.data();
    
    // cout << k << endl;
    
    
    for(int j = 0; j < n; ++j) {  // right
        seg_tree st;
        // st.mod(j + 1, 0);
        st.mod(j, 1);
        dp[j][j] = 1;
        for(int i = j - 1; i >= 0; --i) {  // left
        
            int &ret = dp[i][j];
            ret = dp[i + 1][j] + 1;
            
            if(s[i] == 'o') {
                for(int l = i + 1; l <= j; ++l) {  // l <= j ???
                    
                    if(s[l] == 'f' && ((l == i + 1 || dp[i + 1][l - 1] == 0))) {
                        
                        // cout <<"jhere " << i << ' ' << l << ' ' << j << endl;
                        
                        int left_bound = l + 1, right_bound = min(j + 1, l + 1 + k);
                        
                        // if(i == 0 && j == 4) {
                        //     cout << left_bound << ' ' << right_bound << endl;
                        // }
                        
                        // if(right_bound - left_bound + 1 <= 0)
                        // int ans = (right_bound - left_bound + 1 <= 0) ? 0 : st.q(left_bound, right_bound);
                        int ans = right_bound >= j + 1 ? 0 : st.q(left_bound, right_bound);
                        ret = min(ret, ans);
                    }
                }
            }
            
            // if(s[i] != 'o') {
            //     ret = dp[i + 1][j] + 1;
            // } else {  // find "of" patterns
                
            //     for(int l = i + 1; l < j; ++l) {  // l <= j ???
                    
            //         if(s[l] == 'f' && ((l == i + 1 || dp[i + 1][l - 1] == 0))) {
            //             int left_bound = l + 1, right_bound = min(j, l + 1 + k);
            //             // if(right_bound - left_bound + 1 <= 0)
            //             int ans = (right_bound - left_bound + 1 <= 0) ? 0 : st.q(left_bound, right_bound);
                        
            //             ret = min(ret, ans);
            //         }
            //     }
            // }
            st.mod(i, dp[i][j]);
        }
        
    }
    
    cout << dp[0][n - 1] << endl;
    
    
    
}
