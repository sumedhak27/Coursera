#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> op(int n) {
  vector<int> dp(n+1);
  dp[1] = 0;
  for(int i = 2; i<=n; i++) {
    //int v1 = INT32_MAX, v2 = v1;
    //if(i%2==0) v1 = dp[i/2];
    //if(i%3==0) v2 = dp[i/3];
    //dp[i] = min(dp[i-1], min(v1, v2)) + 1; 
    dp[i] = min(dp[i-1], min( (i%2)? INT32_MAX : dp[i/2], (i%3)? INT32_MAX : dp[i/3]))+1;
  }
  /*
  // THIS SOLUTION REQUIRES EXTRA TIME FOR REVERSING THE SEQUENCE  
  vector<int> seq;
  seq.push_back(n);
  for(int i = n; i>1;) {
    !(i%2) && (dp[i]-1 == dp[i/2]) ? seq.push_back(i/2) : !(i%3) && dp[i]-1 == dp[i/3] ? seq.push_back(i/3) : seq.push_back(i-1);
    i = seq[seq.size()-1]; 
  }
  reverse(seq.begin(), seq.end());
  */
  vector<int> seq(dp[n]+1);
  seq[dp[n]] = n;
  for(int i = n, j = dp[n]-1; i>1 && j>=0; j--) {
    if(!(i%2) && dp[i]-1 == dp[i/2]) 
      seq[j] = i/2;
    else if(!(i%3) && dp[i]-1 == dp[i/3])  
      seq[j] = i/3; 
    else 
      seq[j] = i-1;

    i = seq[j];
  }
  return seq;
}


vector<int> op_seq(int n) {
    vector<int> dp(n+1);
    dp[1] = 0;
    for(int i = 2; i<=n; i++) 
        dp[i] = min(dp[i-1], min((i%2)? INT32_MAX : dp[i/2], (i%3)? INT32_MAX : dp[i/3])) + 1;
    vector<int> seq(dp[n]+1);
    seq[dp[n]] = n;
    for(int i = n, j = dp[n]-1; (i>1 && j>=0); j--) {
        if(!(i%2) && dp[i]-1 == dp[i/2]) 
            seq[j] = i/2;
        else if(!(i%3) && dp[i]-1 == dp[i/3])  
            seq[j] = i/3; 
        else 
            seq[j] = i-1;

        i = seq[j];
    }
    return seq;
}

int main() {
  int n;
  cin >> n;
  //vector<int> sequence = optimal_sequence(n);
  vector<int> sequence = op_seq(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}
