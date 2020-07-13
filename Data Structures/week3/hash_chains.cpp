#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
int m; 
vector<vector<string>> hashtable;

ll hashf(string s) {
    ll x = 1, hash = 0;
    for(auto& c : s) {
        hash = ((hash + ((int)c*x % M)) + M ) % M;
        x = (x*263) % M;
    }
    return hash;
}

bool find(string s, int hashval) {
    for(auto& e : hashtable[hashval]) {
        if(e==s) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m;
    hashtable.resize(m);
    int t; cin>>t;
    string q;
    int hashval; 
    while(t--) {
        cin>>q;
        if(q=="add") {
            string s; cin>>s;
            hashval = hashf(s)%m;
            if(!find(s, hashval)) hashtable[hashval].push_back(s);
        }
        else if(q=="find") {
            string s; cin>>s;
            hashval = hashf(s)%m;
            if(find(s,hashval)) cout<<"yes\n";
            else cout<<"no\n";
        }
        else if(q=="del") {
            string s; cin>>s;
            hashval = hashf(s)%m;
            auto itr = hashtable[hashval].begin();
            for(; itr!=hashtable[hashval].end(); itr++) {
                if(*itr==s) 
                    break;
            }
            if(itr!=hashtable[hashval].end())
                hashtable[hashval].erase(itr);
        }
        else {
            int ind; cin>>ind;
            for(auto itr = hashtable[ind].rbegin(); itr!=hashtable[ind].rend(); itr++) {
                cout<<*itr<<" ";
            }
            cout<<"\n";
        }
    }
}