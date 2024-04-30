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
int dp[301][301];

int32_t main() {
    cin >> input >> k;
    n = input.size();
    s = input.data();
    
    
    for(int j = 0; j < n; ++j) {  // right
        seg_tree st;
        
        for(int i = n - 1; i >= 0; --i) {  // left
        
            int &ret = dp[i][j];
            
            if(s[i] != 'o') {
                ret = dp[i + 1][j] + 1;
                continue;
            }
            
            for(int l = i + 1; l < j; ++l) {
                if(s[l] == 'f' && (i + 1 < l - 1) && dp[i + 1][l - 1] == 0) {
                    
                    
                    ret = min(ret, );
                }
            }
            
            
            
        }
        
        
        
    }
    
    
    
    
}
