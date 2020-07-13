#include <bits/stdc++.h>
using namespace std;


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}


int get_majority_element(vector<int>& a) {
  unordered_map<int,int> mm;
  for(auto& i : a) mm[i]++;
  for(auto& p : mm) if(p.second>(a.size()/2)) return p.first;
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a) != -1) << '\n';
}
