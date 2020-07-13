#include<bits/stdc++.h>
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {
    stack<int> stk;
    int n = A.size();
    int reach[n]{0};
    for(int i = 0; i<n; i++) {
        while(!stk.empty() && A[stk.top()]<A[i]) {
            reach[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()) { 
        reach[stk.top()] = n;
        stk.pop();
    }
    int cind = 0;
    for(int i = 0; i<=n-w; i++) {
        if(cind<i) cind = i;
        while(reach[cind]<i+w){
            cind = reach[cind]; 
        }
        cout<<A[cind]<<" ";
    }
    cout<<endl;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
