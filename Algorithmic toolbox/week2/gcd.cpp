#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd_fast(ll a, ll b) {
  if(b==0) return a;
  return gcd_fast(b, a%b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b) <<endl;
  return 0;
}
