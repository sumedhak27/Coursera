#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int i, ll arr[]) {
    if(arr[i]<=0) return i;
    arr[i] = find(arr[i], arr);
    return arr[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin>>n>>m;
    ll arr[n+1];
    ll max_size = 0;
    for(int i = 1; i<=n; i++) {
        ll t; cin>>t;
        arr[i] = -1*t;
        max_size = max(max_size, t);
    }
    while(m--) {
        int dest, sour; cin>>dest>>sour;
        int psour = find(sour, arr);
        int pdest = find(dest, arr);
        if(psour != pdest) {
            arr[pdest]+=arr[psour];
            arr[psour] = pdest;
            max_size = max(max_size, -1*arr[pdest]);
        }
        cout<<max_size<<"\n";
    }
}