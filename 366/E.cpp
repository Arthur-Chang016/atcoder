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

int n, d;
pair<int, int> ps[200005];

pair<vector<long>, vector<long>> build_pre(vector<long> &arr) {
    sort(arr.begin(), arr.end());
    vector<long> up(n), down(n);
    for(int i = 0; i < n; ++i) {
        down[i] = arr[i] - arr[0];
        up[i] = arr.back() - arr[i];
    }
    // for(int i = n - 2; i >= 0; --i) down[i] += down[i + 1];
    for(int i = 1; i < n; ++i) up[i] += up[i - 1], down[i] += down[i - 1];
    return {up, down};
}

long sum(int l, int r, vector<long> &pre) {
    if(l > r) return 0;
    if(l == 0) return pre[r];
    return pre[r] - pre[l - 1];
}

long sum_dist(int target, vector<long> &arr, vector<long> &up, vector<long> &down) {
    int ind = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int rlen = arr.size() - ind, llen = ind;
    // long rsum = sum(ind, arr.s
    
    
    
}

int32_t main() {
    cin >> n >> d;
    vector<long> h(n), v(n);
    for(int i = 0; i < n; ++i) {
        cin >> ps[i].first >> ps[i].second;
        h[i] = ps[i].first;
        v[i] = ps[i].second;
    }
    
    // sort(h.begin(), h.end());
    // sort(v.begin(), v.end());
    
    auto [hup, hdown] = build_pre(h);
    auto [vup, vdown] = build_pre(v);
    // auto vpre = build_pre(v);
    
    
    
    
    
    
    
    
    
    
}
