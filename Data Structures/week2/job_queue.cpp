#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Thrd {
    ll thread_id, finish_time;
};

struct compare {
    bool operator ()(const Thrd& j1, const Thrd& j2) {
        if(j1.finish_time == j2.finish_time) 
            return j1.thread_id > j2.thread_id;
        return j1.finish_time > j2.finish_time;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll num_threds, num_jobs; cin>>num_threds>>num_jobs;
    ll arr[num_jobs];
    for(ll i = 0; i<num_jobs; i++) cin>>arr[i];
    priority_queue<Thrd, vector<Thrd>, compare> pq;
    for(ll i = 0; i<num_threds; i++) 
        pq.push({i, 0});
    for(ll i = 0; i<num_jobs; i++) {
        Thrd curr_thrd = pq.top();
        pq.pop();
        cout<<curr_thrd.thread_id<<" "<<curr_thrd.finish_time<<"\n";
        curr_thrd.finish_time+=arr[i];
        pq.push(curr_thrd);
    }
}