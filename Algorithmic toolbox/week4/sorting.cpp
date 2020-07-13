#include <bits/stdc++.h>
using namespace std;

/*
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}
*/
int medianOf3(int a, int b, int c){
  int minn = min(min(a,b),c);
  int maxx = max(max(a,b),c);
  if(a!=minn || a!=maxx) return a;
  if(b!=minn || b!=maxx) return b;
  return c;
}

void partition(vector<int>& a, int l, int h, int& i, int& j) {
  int pivot = a[l];
  int eq=l+1;
  i = l+1, j = l+1;
  while(i<=h) {
    if(a[i]<=pivot) {
      swap(a[i],a[j]);
      if(a[j]<pivot)
        swap(a[j],a[eq++]);
      i++,j++;
    }
    else i++;
  }
  swap(a[l], a[eq-1]);
  i = eq-2;
}

void quick_sort(vector<int>& a, int l, int h) {
  if(l<h) {
    int i ,j;
    int k = l + rand() % (h - l + 1);
    swap(a[l],a[k]);
    partition(a, l, h, i, j);
    quick_sort(a, l, i);
    quick_sort(a, j, h);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
