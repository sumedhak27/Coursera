#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

double cal_dist(Point p1, Point p2) {
	return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

double cal_hybrid_min(vector<Point> left_part, vector<Point> right_part, int c_line, int smin) {
	vector<Point> reduced_part;
	for(Point p: left_part) 
		if(abs(c_line-p.x) <= smin) reduced_part.push_back(p);
	for(Point p: right_part)
		if(abs(p.x-c_line) <= smin) reduced_part.push_back(p);
	sort(reduced_part.begin(), reduced_part.end(), [](const Point& p1, const Point& p2) {return p1.y<p2.y;});
	double mini = FLT_MAX;
	// cout<<"test : "<<reduced_part.size()<<endl;
	for(int i = 0 ; i<reduced_part.size(); i++) {
		for(int j = i+1; j<reduced_part.size(); j++) {
			if(abs(reduced_part[i].y - reduced_part[j].y)<=smin) 
				mini = min(mini, cal_dist(reduced_part[i], reduced_part[j]));
			else 
				break; 
		}
	}
	return mini;
}

double rec_min_dist(vector<Point> points) {
	int n = points.size();
	if(n<=3) {
		double mini = FLT_MAX;
		for(int i = 0; i<n-1; i++)  
			for(int j = i+1; j<n; j++) 
				mini = min(mini, cal_dist(points[i], points[j]));
		return mini;
	}
	
	vector<Point> left_part(points.begin(), points.begin()+n/2);
	vector<Point> right_part(points.begin()+n/2, points.end());

	double seperate_min = min(
		rec_min_dist(left_part),
		rec_min_dist(right_part)
	);

	int centre_line = ((long long)left_part[n/2-1].x+(long long)right_part[0].x)/2;
	
	double hydrid_min = cal_hybrid_min(left_part, right_part, centre_line, seperate_min);

	return min(hydrid_min, seperate_min);
}

double minimal_distance(vector<int> x, vector<int> y) {
	vector<Point> points;
	for(int i = 0; i<x.size(); i++) points.push_back(Point(x[i], y[i]));
	sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) { return p1.x<p2.x;});
	return rec_min_dist(points);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	size_t n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (size_t i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	cout << fixed;
	cout << setprecision(9) << minimal_distance(x, y) << "\n";
}
