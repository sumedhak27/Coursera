#include <bits/stdc++.h>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  multimap<double,int, greater<int>> valpnw;
  for(int i = 0; i<values.size(); i++) {
    valpnw.insert({(1.0*values[i])/weights[i], weights[i]});
  }

  for(auto itr : valpnw) {
    //cout<<itr.first<<" "<<itr.second<<endl;
    int a = min(capacity, itr.second);
    value+=(a*itr.first);
    capacity-=a;
    if(!capacity) break;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
