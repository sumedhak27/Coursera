#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int arr[n];
    vector<pair<int,int>> swaps;
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = n/2; i>=0; i--) {
        int j = i; 
        while(1) {
            int minele = arr[j], minind = j;
            if(2*j+1<n && arr[2*j+1]<minele) (minind = 2*j+1, minele = arr[minind]);
            if(2*j+2<n && arr[2*j+2]<minele) (minind = 2*j+2, minele = arr[minind]);
            if(minind == j) break;
            else (swaps.push_back({j,minind}), swap(arr[j],arr[minind]), j = minind);
        }
    }
    cout<<swaps.size()<<"\n";
    for(auto& i : swaps) cout<<i.first<<" "<<i.second<<"\n";
}