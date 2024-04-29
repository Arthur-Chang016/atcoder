#include <bits/stdc++.h>
using namespace std;

static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();

// struct t {
//     int x, h, ind;
    
//     bool operator <(const t& r) const {
//         return this->x < r.x;
//     }
// };

int n;

#define N 100005
// t arr[N];
array<int, 3> arr[N];

int tree[N * 2];

inline int q(int l, int r) {
    l += n, r += n;
    int ret = tree[l];
    while(l <= r) {
        if(l % 2 == 1) ret = max(ret, tree[l++]);
        if(r % 2 == 0) ret = max(ret, tree[r--]);
        l /= 2, r /= 2;
    }
    return ret;
}

inline void update(int i, int k) {
    i += n;
    tree[i] = k;
    for(i /= 2; i >= 1; i /= 2)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    
    sort(arr, arr + n, [](auto const &a, const auto &b) {
        return a[0] < b[0];
    });
    
    vector<int> ret(n);
    
    // segtree : store the right bound of each dominos
    
    for(int i = n - 1; i >= 0; --i) {
        auto [x, h, retind] = arr[i];
        // find the right bound, first LE
        int ind = upper_bound(arr + i + 1, arr + n, array<int, 3>{x + h - 1, 0, 0}, [](const auto &a, const auto &b) {
            return a[0] < b[0];
        }) - arr;
        
        
        --ind;
        
        // int ind = upper_bound(arr + i + 1, arr + n, x + h) - arr;
        // upper_bound(arr + i + 1, arr + n, x + h);
        
        // int ind;
        
        if(ind >= i + 1) {
            int ma = q(i + 1, ind);
            
            ret[retind] = ma - i + 1;
            update(i, ma);
        } else {
            ret[retind] = 1;
            update(i, i);
        }
        
        
        // if(ind - 1 >= 0) --ind;
        // else {
        //     continue;
        // }
        
        // int r = q(i + 1, ind);
        
        // cout << x << ' ' << h << ' ' << ind <<' ' << r << endl;
        
        // ret[retind] = r + 1;
        // update(i, r);
    }
    for(int i = 0; i < n; ++i)
        cout << ret[i] << ' ';
}