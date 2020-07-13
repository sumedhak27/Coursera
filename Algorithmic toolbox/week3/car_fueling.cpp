#include <iostream>
#include <vector>
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.insert(stops.begin(),0);
    stops.push_back(dist);
    int nofr = 0, sp = 0;
    for(int i = 0; i<stops.size()-1; i++) {
        if(stops[i+1]-stops[sp]<=tank) continue;
        else if(i==sp) return -1;
        else {
            sp = i--;
            nofr++;
        }
    }
    return nofr;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
