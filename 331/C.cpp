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

#define N 1000005
long tree[N * 2];

long q(int l, int r) {
    l += N, r += N;
    long ret = 0;
    while(l <= r) {
        if(l % 2 == 1) ret += tree[l++];
        if(r % 2 == 0) ret += tree[r--];
        l/= 2, r /= 2;
    }
    return ret;
}


int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        tree[tmp + N] += tmp;
        arr[i] = tmp;
    }
    // build
    for(int i = N - 1; i >= 0; --i) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    
    for(int i = 0; i < n; ++i) {
        long ret = q(arr[i] + 1, 1000000);
        cout << ret << ' ';
    }cout << endl;
    
    
}