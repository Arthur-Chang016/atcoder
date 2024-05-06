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
    long n;
    cin >> n;
    
    while(n % 2 == 0 || n % 3 == 0) {
        if(n % 2 == 0) n /= 2;
        if(n % 3 == 0) n /= 3;
    }
    
    if(n == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
}
