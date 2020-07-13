#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> value;
vector<int> lefta, righta;

bool dfs(int node, ll low, ll high) {
    if(node==-1) return true;
    if(value[node]>=low && value[node]<high) {
        return (dfs(lefta[node], low, value[node]) && dfs(righta[node], value[node], high));
    }
    return false;
}

int main() {
    int n; cin>>n;
    if(!n) {cout<<"CORRECT"<<endl; return 0;}
    value.resize(n);
    lefta.resize(n);
    righta.resize(n);
    for(int i = 0; i<n; i++) cin>>value[i]>>lefta[i]>>righta[i];
    bool bst = dfs(0, LONG_LONG_MIN, LONG_LONG_MAX);
    if(bst) cout<<"CORRECT"<<endl;
    else cout<<"INCORRECT"<<endl;
}