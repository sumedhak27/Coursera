#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector <bool> isroot;
  int root;
public:
  void read() {
    cin >> n;
    isroot.resize(n,0);
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
      isroot[left[i]] = 1;
      isroot[right[i]] = 1;
    }
    for(int i = 0; i<n; i++) {
      if(!isroot[i]) {
        root = i;
        break;
      }
    }
  }

  void recin(int r, vector<int>& res) {
      if(!r) return;
      recin(left[r], res);
      res.push_back(r);
      recin(right[r], res);
  }

  vector <int> in_order() {
    vector<int> result;
    recin(root,result);
    return result;
  }

  void recpre(int r, vector<int>& res) {
    if(!r) return;
    res.push_back(r);
    recpre(left[r], res);
    recpre(right[r], res);
  }

  vector <int> pre_order() {
    vector<int> result;    
    recpre(root, result);
    return result;
  }

  void recpost(int r, vector<int>& res) {
    if(!r) return;
    recpost(left[r], res);
    recpost(right[r], res);
    res.push_back(r);
  }

  vector <int> post_order() {
    vector<int> result;
    recpost(root, result);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

