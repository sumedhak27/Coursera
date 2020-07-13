#include <bits/stdc++.h>
using namespace std;

bool comparef(const string& a, const string& b) {
  int i = 0, j =0;
  while(1) {
    // cout<<i<<","<<j<<" | "<<a[i]<<" : "<<b[j]<<endl;
    if(a[i]!=b[j]) return a[i]>b[j];
    else {
      bool ch = 0;
      if(i+1<a.size()) {i++; ch=1;}
      if(j+1<b.size()) {j++; ch=1;}
      if(!ch) break;
    }
  } 
  return 0;
}

string largest_number(vector<string> a) {
  sort(a.begin(),a.end(), comparef);
  stringstream ret;
  string result;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  ret >> result;
  return result;
}

bool isgreater(string n, string max) {
  return stoi(n+max) > stoi(max+n);
}

string largest_num(vector<string> a) {
  string ans = "";
  while(!a.empty()) {
    string max = "0";
    auto itr = a.begin(), max_itr = a.begin();
    for(auto& n : a) {
      if(isgreater(n,max)) {max = n; max_itr = itr;}
      itr++;
    }
    a.erase(max_itr);
    ans.append(max);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout<<largest_num(a);
  //cout << largest_number(a);
}
