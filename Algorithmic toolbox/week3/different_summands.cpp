#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> optimal_summands(ll n) {
  vector<ll> summands;
  if(n == 1) {summands.push_back(1); return summands;}
  ll sum = 0;
  for(ll i = 1; i<n && sum<n; i++) {
    if(n-(sum+i)>i) {
      summands.push_back(i);
      sum+=i;
    }
    else {
      summands.push_back(n-sum);
      break;
    }
  }
  return summands;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
