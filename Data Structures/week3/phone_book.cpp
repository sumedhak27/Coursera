#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    vector<string>phonebook((int)1e7+1,"");
    while(t--) {
        string q;
        cin>>q;
        if(q=="find") {
            int num; 
            cin>>num;
            if(phonebook[num]=="") cout<<"not found\n";
            else cout<<phonebook[num]<<"\n";
        }
        else if(q=="add") {
            int num;
            string name;
            cin>>num>>name;
            phonebook[num] = name;
        }
        else {
            int num;
            cin>>num;
            phonebook[num]="";
        }
    }

}