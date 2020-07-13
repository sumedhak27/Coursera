#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lcs(vector<int>& x, vector<int>& y) {
  int l = x.size(), m = y.size();
  vector<vector<int>> dp;
  dp.resize(l+1, vector<int>(m+1));
  for(int i = 0; i<=l; i++) {
    for(int j = 0; j<=m; j++) {
      if(!i || !j) dp[i][j]=0;
      else {
        if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  } 
  return dp;
}

vector<int> getseq(vector<vector<int>>& dp, vector<int>&x, vector<int>&y) {
  int l = x.size(), m = y.size();
  vector<int> xy(dp[l][m]);
  for(int i = l, j = m, k = dp[l][m]-1; i>0, j>0, k>=0; ) {
    if(dp[i][j] == dp[i-1][j-1]+1 && x[i-1] == y[j-1]) {xy[k--] = y[j-1]; i--; j--;}
    else if(dp[i][j] == dp[i][j-1]) j--;
    else i--;
  }
  return xy;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

  vector<vector<int>> dp1 = lcs(a,b);
  vector<int> ab = getseq(dp1, a, b);
  for(auto&i : ab) cout<<i<<" ";
  cout<<endl;
  vector<vector<int>> dp2 = lcs(b, c);
  vector<int> bc = getseq(dp2, b, c);
  for(auto&i : bc) cout<<i<<" ";
  cout<<endl;
  vector<vector<int>> dp3 = lcs(ab, bc);
  return dp3[ab.size()][bc.size()];
  /*
  int l = a.size(), m = b.size(), n = c.size();
  int dp[l+1][m+1];
  for(int i = 0; i<=l; i++) {
    for(int j = 0; j<=m; j++) {
      if(!i || !j) dp[i][j]=0;
      else {
        if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  } 

  vector<int> ab(dp[l][m]);
  for(int i = l, j = m, k = dp[l][m]-1; i>0, j>0; ) {
    if(dp[i][j] == dp[i-1][j-1]+1 && a[i-1] == b[j-1]) {ab[k--] = b[j-1]; i--; j--;}
    else if(dp[i][j] == dp[i][j-1]) j--;
    else i--;
  }
  */


  return min(min(a.size(), b.size()), c.size());
}

int lcs3d(vector<int>& a, vector<int>& b, vector<int>& c) {
  int l = a.size(), m = b.size(), n = c.size();
  int dp[l+1][m+1][n+1];
  for(int i = 0; i<=l; i++) {
    for(int j = 0; j<=m; j++) {
      for(int k = 0; k<=n; k++) {
        if(!i || !j ||!k) dp[i][j][k] = 0;
        else {
          if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
            dp[i][j][k] = dp[i-1][j-1][k-1]+1;
          else {
            dp[i][j][k] = max(dp[i-1][j][k],
                              max(dp[i][j-1][k],
                                  max(dp[i][j][k-1],
                                      max(dp[i-1][j-1][k],
                                          max(dp[i][j-1][k-1],
                                              dp[i-1][j][k-1]
                                              )
                                          )
                                      )
                                  )
            );
          }
        }
      }
    }
  }
  return dp[l][m][n];
}

int main() {
  ios:: sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  size_t an;
  cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    cin >> a[i];
  }
  size_t bn;
  cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    cin >> b[i];
  }
  size_t cn;
  cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    cin >> c[i];
  }
  cout << lcs3d(a, b, c) << endl;
}
