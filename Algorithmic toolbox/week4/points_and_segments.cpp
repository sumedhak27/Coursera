#include <bits/stdc++.h>
using namespace std;

bool comparef(const pair<int,int>& p1, const pair<int,int>& p2) {
	if(p1.first == p2.first) 
		return p1.second<p2.second;
	return p1.first<p2.first;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	vector<pair<int, int>> allpts;
	unordered_map<int, int> ans;
	for(int i = 0; i<starts.size(); i++) {
		allpts.push_back({starts[i], 0});
		allpts.push_back({ends[i], 2});
	}
	for(int i = 0; i<points.size(); i++) 
		allpts.push_back({points[i], 1});

	sort(allpts.begin(), allpts.end(), comparef);
	int segcount = 0;

	for(int i = 0; i<allpts.size(); i++) {
		if(allpts[i].second == 0) 
			segcount++;
		else if(allpts[i].second == 2) 
			segcount--;
		else 
			ans[allpts[i].first]=segcount;
	}
	for(int i = 0; i<points.size(); i++) 
		cnt[i] = ans[points[i]];

	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) {
		cin >> points[i];
	}
	// use fast_count_segments
	// vector<int> cnt = naive_count_segments(starts, ends, points);
	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << ' ';
	}
}


vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}