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

int n;
pair<long, long> arr[200005];

int32_t main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
        
    sort(arr, arr + n);
    
    priority_queue<long, vector<long>, greater<>> q;  // only put end time
    
    long curtime = 0;
    int ind = 0;
    int ret = 0;
    while(ind < n || !q.empty()) {
        // update curtime
        if(q.empty()) {  
            curtime = arr[ind].first;
        }
        
        // update things less than equal to current time
        while(ind < n && arr[ind].first <= curtime) {
            q.push(arr[ind].first + arr[ind].second);
            ind++;
        }
        
        // pop one with earliest end time
        if(!q.empty()) {
            q.pop();
            curtime++;
            ++ret;
        }
        // pop all outdated
        while(!q.empty() && q.top() < curtime) {
            q.pop();
        }
        
    }
    cout << ret << endl;
    
    
}
