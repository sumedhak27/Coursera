#include <bits/stdc++.h>
using namespace std;

struct Thrd {
  long long thread_id, finish_time;
};

struct compare {
  bool operator ()(const Thrd& t1, const Thrd& t2) {
    if(t1.finish_time == t2.finish_time)
      return t1.thread_id > t2.thread_id;
    return t1.finish_time > t2.finish_time;
  }
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

    void AssignJobs2() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<Thrd, vector<Thrd>, compare> pq;
    for(int i = 0; i<num_workers_; i++) 
      pq.push({i, 0});
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      Thrd next_worker = pq.top();
      pq.pop();
      assigned_workers_[i] = next_worker.thread_id;
      start_times_[i] = next_worker.finish_time;
      next_worker.finish_time += duration;
      pq.push(next_worker);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs2();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
