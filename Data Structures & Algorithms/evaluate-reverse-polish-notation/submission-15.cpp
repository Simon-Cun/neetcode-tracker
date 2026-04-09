#include <stack>
#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& s : tokens) {
            if (s == "+") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 + op1);
            } else if (s == "*") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 * op1);
            } else if (s == "-") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 - op1);
            } else if (s == "/") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push((double)op2 / op1);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
