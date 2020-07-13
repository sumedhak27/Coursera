#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int n = str1.length(), m = str2.length();
    //vector<vector<int>> dp(m+1, vector<int>(n+1));
    int dp[m+1][n+1];
    //memset(dp, 0, sizeof(dp));
    for(int i = 0; i<=n; i++) dp[0][i] = i;
    for(int i = 1; i<=m; i++) dp[i][0] = i;
    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            if(str1[j-1] == str2[i-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            //if(str1[j-1] != str2[i-1]) dp[i][j]++;
        }
    }
    /*
    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++) 
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    */
    return dp[m][n];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}
