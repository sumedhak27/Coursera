#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val, maxVal;
    Node* next;
    Node(int v, Node* nxt) : val(v) , next(nxt) {}
};

struct Stack {
    Node* top = nullptr;
    void push(int val) {
        Node *nn = new Node(val, nullptr);
        if(!top)
            nn->maxVal = val;   
        else {
            nn->maxVal = max(val, top->maxVal);
            nn->next = top;
        }
        top = nn;
    }
    void pop() {
        Node* t = top;
        top = top->next;
        delete(t);
    }
    int getmax() {
        return top->maxVal;
    }
};


int main() {
    int q; cin>>q;
    Stack stk;
    while(q--) {
        string query;
        cin>>query;
        if(query=="push") {
            int val; cin>>val;
            stk.push(val);
        }
        else if(query=="pop") {
            stk.pop();
        }
        else {
            cout<<stk.getmax()<<endl;
        }
    }
}