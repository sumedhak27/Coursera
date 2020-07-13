#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_fibonacci_huge(ll n, ll m) {
    if (n <= 1)
        return n;
    vector<ll> fib{0,1};
    bool brk = 0;
    for (ll i = 2; i <= n ; i++) {
        fib.push_back((fib[i-1]+fib[i-2])%m);
        if(fib[i-1] == 0 && fib[i] == 1) {
            brk = 1;
            break;
        } 
    }
    if(brk)
        return fib[n%(fib.size()-2)];
    else
        return fib[n]; 
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << '\n';
}
