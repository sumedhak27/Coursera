#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_fibonacci_partial_sum_fast(ll from , ll to) {
    int sum1,sum2;
    sum1 = to==0? 0 : 1;
    sum2 = (from==0 || from==1) ? 0 : 1; 
    vector<ll> fib{0, 1};
    bool brk = 0;
    for(int i = 2; i<=to; i++) {
        fib.push_back((fib[i-1]+fib[i-2])%10);
        if(fib[i-1] == 0 && fib[i] == 1) {
            brk = 1;
            break;
        }
        sum1=(sum1+fib[i])%10;
        if(i<from) sum2=sum1;
        // cout<<sum1<<" "<<sum2<<"\n";
    }
    // cout<<brk<<endl;
    if(brk) {
        if(sum1 == sum2) {
            sum2*=floor(from/(fib.size()-2));
            sum2%=10;
            for(int i = 0; i<from%(fib.size()-2); i++) sum2=(sum2+fib[i])%10;
        }
        sum1*=floor(to/(fib.size()-2));
        sum1%=10;
        for(int i = 0; i<=to%(fib.size()-2); i++) sum1=(sum1+fib[i])%10;
    }
    if(sum1<sum2) return (10+sum1)-sum2;
    return sum1-sum2;
}

int main() {
    ll from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
