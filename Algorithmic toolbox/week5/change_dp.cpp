#include <bits/stdc++.h>
using namespace std;

int coins[3]{1,3,4};

int get_change(int m) {
  int change[m+1];
  for(int i = 1; i<=m; i++) change[i] = INT32_MAX;
  change[0] = 0;
  for(int& c : coins) 
    for(int i = c; i<=m; i++) 
      change[i] = min(change[i], change[i-c]+1);
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
