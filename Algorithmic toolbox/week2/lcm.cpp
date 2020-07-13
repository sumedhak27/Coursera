#include <iostream>
typedef long long ll;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm_fast(ll a, ll b) {
  return (a*b)/gcd(a,b);
}

int main() {
  ll a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
