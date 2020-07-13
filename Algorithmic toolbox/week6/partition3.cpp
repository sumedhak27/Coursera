#include <bits/stdc++.h>
using namespace std;

vector<int> recsol(vector<int> A, int sum, int csum, int i) {
    
}

int partition3(vector<int> &A) {
    //write your code here
    int tsum = 0;
    tsum = accumulate(A.begin(), A.end(), tsum);
    if(tsum%3) return 0;
    int sum = tsum/3;
    vector<int> nA = recsol(A, sum, 0, 0);
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        cin >> A[i];
    }
    cout << partition3(A) << '\n';
}
