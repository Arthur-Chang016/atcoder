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

struct S{
    int t, w, s;
};

int n, m;
S arr[100005];

int32_t main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        cin >> arr[i].t >> arr[i].w >> arr[i].s;
    }
    
    // * 10
    priority_queue<long, vector<long>, greater<>> p;  // people
    
    sort(arr, arr + m, [](S a, S b) {
        return a.t < b.t;
    });
    
    // time, {people, num}
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> events;
    
    
    
    
    
    
    
}
