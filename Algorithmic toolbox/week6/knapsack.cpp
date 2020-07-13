#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll optimal_weight(ll W, const vector<ll> &w) {
    ll n = w.size();
    vector<vector<ll>>dp(n+1, vector<ll>(W+1, 0));
    for(ll i = 1; i<=n; i++) {
        for(ll j = 1; j<=W; j++) {
            if(w[i-1]<=j) 
                dp[i][j] = max((w[i-1] + dp[i-1][j-w[i-1]]), dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j]; 
        }
    }   
    return dp[n][W];
}

int main() {
    ll n, W;
    cin >> W >> n;
    vector<ll> w(n);
    for (ll i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << optimal_weight(W, w) << '\n';
}
