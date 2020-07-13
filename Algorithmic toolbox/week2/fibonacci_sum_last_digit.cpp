#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fibonacci_sum_fast(ll n) {
    if (n <= 1)
        return n;
    vector<ll> fib{0,1};
    bool brk = 0;
    int sum = 1;
    for (ll i = 2; i <= n ; i++) {
        fib.push_back((fib[i-1]+fib[i-2])%10);
        if(fib[i-1] == 0 && fib[i] == 1) {
            brk = 1;
            break;
        } 
        sum=(sum+fib[i])%10;
    }
    if(brk) {
        sum*=floor(n/(fib.size()-2));
        sum%=10;
        for(int i = 0; i<=n%(fib.size()-2); i++) sum = (sum+fib[i])%10;
    }
    return sum; 
}

int main() {
    ll n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
