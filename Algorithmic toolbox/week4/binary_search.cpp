#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int binary_search(const vector<ll> &a, ll x) {
  int low = 0, high = (int)a.size(); 
  while(low<=high) {
    int mid = (low+high)/2;
    if(a[mid] == x) return mid;
    else if(a[mid]<x) low = mid+1;
    else high = mid-1;
  }
  return -1;
}

int binary_search_rec(const vector<ll>& a, ll x, int low, int high) {
  if(low>high) return -1;
  int mid = (low+high)/2;
  if(a[mid] == x) return mid;
  else if(a[mid]<x) return binary_search_rec(a,x,mid+1,high);
  else return binary_search_rec(a,x,low,mid-1);
}

int linear_search(const vector<ll> &a, ll x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<ll> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cout << binary_search(a, b[i]) <<' ';
    //cout<<binary_search_rec(a, b[i], 0, a.size()-1)<<" ";
  }
}
