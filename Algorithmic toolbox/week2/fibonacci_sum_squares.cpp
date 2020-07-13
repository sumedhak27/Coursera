#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(ll n) {
    if (n <= 1)
        return n;
    vector<ll> fib{0,1};
    bool brk = 0;
    for (ll i = 2; i <= n+1 ; i++) {
        fib.push_back((fib[i-1]+fib[i-2])%10);
        if(fib[i-1] == 0 && fib[i] == 1) {
            brk = 1;
            break;
        } 
    }
    if(brk)
        return (fib[n%(fib.size()-2)]*fib[(n%(fib.size()-2))+1])%10;
    else
        return (fib[n]*fib[n+1])%10; 

}

int main() {
    ll n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
