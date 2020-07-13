#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
vector<vector<int>> graph;

int getmaxheight(int i) {
  if(graph[i].empty()) return 1;
  int maxh = INT32_MIN;
  for(auto& child : graph[i]) {
    maxh = max(maxh, getmaxheight(child)+1);
  }
  return maxh;
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  graph.resize(n, vector<int>());
  int root;
  for(int i = 0; i<n; i++) {
    int parent;  cin>>parent;
    if(parent==-1) root = i;
    else graph[parent].push_back(i);
  }
  cout<<getmaxheight(root)<<endl;
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
              cerr << "setrlimit returned result = " << result << endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}