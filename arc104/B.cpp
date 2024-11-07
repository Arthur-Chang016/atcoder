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

int32_t main() {
    int n;
    string s;
    cin >> n >> s;
    
    for(char &c: s) {
        if(c == 'A') c = 0;
        else if(c == 'T') c = 1;
        else if(c == 'C') c = 2;
        else c = 3;
    }
    
    // cout << s << endl;
    // for(int i: s) cout << i ; cout << endl;
    
    // atcg
    vector<vector<int>> arr(n + 1, vector<int>(4, 0));
    
    for(int i = 0; i < n; ++i) {
        char c = s.at(i);
        auto last = arr[i];
        last[c]++;
        arr[i + 1] = move(last);
    }
    
    // for(auto a : arr) {
    //     for(int i =  0; i < 4; ++i) {
    //         cout << a[i] << ' ';
    //     }
    //     cout << endl;
    // }
    
    long ret = 0;
    for(int i = 1; i <= n; ++i) {
        auto &r = arr[i];
        
        for(int j = 0; j < i; ++j) {
            auto &l = arr[j];
            
            vector<int> diff(4, 0);
            for(int k = 0; k < 4; ++k) diff[k] = r[k] - l[k];
            
            // check
            bool ans = diff[0] == diff[1] && diff[2] == diff[3];
            ret += ans;
        }
    }
    cout << ret << endl;
    
}
