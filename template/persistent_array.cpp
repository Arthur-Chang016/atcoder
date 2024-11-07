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

template<typename T>
struct per_arr {
    vector<vector<pair<int, T>>> arr;
    
    per_arr(int n, int time, T init) : arr(n, vector<pair<int, T>>(1, {time, init})) {}
    
    void add(int i, int time, T num) {
        assert(i < arr.size());
        assert(arr[i].empty() || arr[i].back().first <= time);
        
        if(arr[i].empty() || arr[i].back().first < time) {
            arr[i].push_back({time, num});
        } else {  // arr[i].back().first == time
            arr[i].back().second = num;
        }
    }
    
    // number less than or equal to the time
    T at(int i, int time) {
        assert(i < arr.size());
        vector<pair<int, T>> &idx = arr[i];
        const T MAX = numeric_limits<T>::max();
        auto it = upper_bound(idx.begin(), idx.end(), pair<int, T>{time, MAX});
        assert(it != idx.begin());
        return prev(it)->second;
    }
};

template<typename T>
struct per_segtree {
    per_arr<T> tree;
    
    per_segtree(int n, T init) : tree(n * 2 + 5, -1, init) {}
    
    T q(int l, int r, int time) {
        const int n = tree.arr.size() / 2;
        l += n, r += n;
        int ret = 0;
        while(l <= r) {
            if(l % 2 == 1) ret += tree.at(l++, time);
            if(r % 2 == 0) ret += tree.at(r--, time);
            l /= 2, r /= 2;
        }
        return ret;
    }
    
    void mod(int i, int k, int time) {
        const int n = tree.arr.size() / 2;
        i += n;
        tree.add(i, time, k);
        for(i /= 2; i >= 1; i /= 2) {  // tree[i] = tree[i * 2] + tree[i * 2 + 1];
            T num = tree.at(i * 2, time) + tree.at(i * 2 + 1, time);
            tree.add(i, time, num);
            
        }
    }
    
};

int32_t main() {
    int n = 10;
    
    // per_arr<int> arr(n, -1, 0);
    
    // arr.add(0, 1, 5);
    // cout << arr.at(0, 1) << endl;
    
    // arr.add(0, 2, 6);
    // cout << arr.at(0, 10) << endl;
    
    
    per_segtree<int> seg(n, 0);
    
    // seg.mod(0, 1, 0);
    // seg.mod(1, 1, 0);
    // seg.mod(0, 1, 0);
    
    for(int i = 0; i < n; ++i)
        seg.mod(i, i + 1, i);
    
    cout << seg.q(0, 9, 8) << endl;
    
    
}