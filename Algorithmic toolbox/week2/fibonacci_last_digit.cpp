#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int get_fibonacci_last_digit_naive(ll n) {
    if (n <= 1)
        return n;
    int previous = 0;
    int current  = 1;
    for (int i = 2; i <=n; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    return current;
}

int main() {
    ll n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
    }
