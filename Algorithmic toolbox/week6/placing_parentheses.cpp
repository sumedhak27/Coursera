#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
ll eval (ll a,  ll b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}
 
ll get_maximum_value(const string &exp) {
    ll n = exp.size()/2+1;
    ll dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(ll k = 0; k<n; k++) {
        for(ll i = 0, j = k; j<n; i++, j++) {
            //setdp(i,j,exp);
            if(i==j) {
                dp[i][j] = (ll)(exp[2*i]-'0');
            }
            else {
                ll mini = LONG_LONG_MAX;
                ll maxi = LONG_LONG_MIN;
                for(ll s = i; s<j; s++) {
                    char op = exp[(2*s)+1];
                    ll c1 = eval(dp[i][s], dp[s+1][j], op);
                    ll c2 = eval(dp[s][i], dp[j][s+1], op);
                    ll c3 = eval(dp[i][s], dp[j][s+1], op);
                    ll c4 = eval(dp[s][i], dp[s+1][j], op);
                    mini = min(mini, min(c1, min(c2, min(c3, c4))));
                    maxi = max(maxi, max(c1, max(c2, max(c3, c4))));
                }
                dp[i][j] = mini;
                dp[j][i] = maxi;
            }
        }
    }
    /**/
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++)
            cout<<"\t"<<dp[i][j]<<"\t";
        cout<<endl;
    }
    /**/
    return dp[n-1][0];
}

int main() {
    string s;
    cin >> s;
    cout << get_maximum_value(s) << '\n';
}
