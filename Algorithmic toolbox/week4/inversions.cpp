#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(vector<int>& a, ll l, ll mid, ll h, ll& count) {
  vector<int> left(a.begin()+l, a.begin()+mid+1);
  vector<int> right(a.begin()+mid+1, a.begin()+h+1);
  ll i = 0, j = 0, k = l;
  while(i<left.size() && j<right.size()) {
    if(right[j]<left[i]) {
      a[k++]=right[j++];
      count+=(left.size()-i);
    } 
    else
      a[k++]=left[i++];
  }
  while(i<left.size()) {
    a[k++] = left[i++];
  }
  while(j<right.size()) {
    a[k++] = right[j++];
  }
}

ll getNumOfInv(vector<int>& a, ll l, ll h) {
  if(l>=h) return 0;
  ll count = 0;
  ll mid = (l+h)/2;
  count+=getNumOfInv(a,l,mid);
  count+=getNumOfInv(a,mid+1,h);
  merge(a,l,mid,h,count);
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  //cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
  cout<<getNumOfInv(a, 0, a.size()-1)<<endl;
  //for(auto& i: a) cout<<i<<" ";
  //cout<<endl;
}
