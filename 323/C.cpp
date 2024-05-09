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

int n, m;
int A[101];
vector<string> S;



int32_t main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) cin >> A[i];
    
    for(int i = 0; i < n; ++i) {
        S.emplace_back();
        cin >> S.back();
    }
    
    // find max
    int ma = 0;
    for(string &s: S) {
        int sum = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'o') sum += A[i];
        }
        ma = max(ma, sum);
    }
    
    for(string &s: S) {
        int sum = 0;
        vector<int> left;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'o') sum += A[i];
            else left.push_back(A[i]);
        }
        
        int diff = sum - ma;
        
        sort(begin(left), end(left));
        
        int add = 0, cnt = 0;
        for(int i = left.size() - 1; i >= 0; --i) {
            
            if(add >= diff) break;
            cnt++;
            add += left[i];
        }
        if(add < diff) ++cnt;
        
        cout << cnt << '\n';
        
        
        
        
    }
    
    
    
    
    
}
