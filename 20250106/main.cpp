#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i); 
            } else { 
                if (st.empty() || 
                    (st.top() == '(' && i != ')') || 
                    (st.top() == '{' && i != '}') || 
                    (st.top() == '[' && i != ']')) {
                    return false; 
                }
                st.pop(); 
            }
        }
        return st.empty(); 
    }
};

int main() {
    Solution solution;
    string test1 = "()[]{}";
    string test2 = "([)]";
    string test3 = "{[]}";
    
    cout << "Test 1: " << (solution.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (solution.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (solution.isValid(test3) ? "Valid" : "Invalid") << endl;

    
    cout << "Press Enter to exit...";
    cin.get(); 

    return 0;
}

