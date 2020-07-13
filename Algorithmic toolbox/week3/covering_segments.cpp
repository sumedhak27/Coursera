#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Segment {
  ll start, end;
};

bool comparef(const Segment& s1, const Segment& s2) {
  return s1.start<s2.start;
}

vector<ll> optimal_polls(vector<Segment> &segments) {
  vector<ll> polls;
  sort(segments.begin(), segments.end(), comparef);  
  //for(auto& i: segments) cout<<i.start<<" : "<<i.end<<"\n";
  ll sp = segments[0].start, ep = segments[0].end;
  for(ll i = 1 ; i<segments.size(); i++) { 
    ll nsp = max(sp, segments[i].start), nep = min(ep, segments[i].end);
    if(nsp<=nep) {sp = nsp; ep = nep;}
    else {
      polls.push_back(ep);
      sp = segments[i].start;
      ep = segments[i].end;
    }
  }
  polls.push_back(ep);
  return polls;
}

int main() {
  ll n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<ll> polls = optimal_polls(segments);
  cout << polls.size() << "\n";
  for (size_t i = 0; i < polls.size(); ++i) {
    cout << polls[i] << " ";
  }
}
