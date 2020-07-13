#include <bits/stdc++.h>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack <Bracket> opening_brackets_stack;
    for (int position = 1; position <= text.length(); ++position) {
        char next = text[position-1];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push({next, position});
        }

        else if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)) 
                opening_brackets_stack.pop();
            else {
                cout<<position<<endl;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.empty()) 
        cout<<"Success"<<endl;
    else {
        int ans = 0;
        while(!opening_brackets_stack.empty()) {
            ans = opening_brackets_stack.top().position;
            opening_brackets_stack.pop();
        }
        cout<<ans<<endl;
    }

    return 0;
}
