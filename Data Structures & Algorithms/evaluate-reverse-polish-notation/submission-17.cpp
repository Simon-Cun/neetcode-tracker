#include <stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& i : tokens) {
            if (i == "+") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 + op1);
            } else if (i == "-") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 - op1);
            } else if (i == "*") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 * op1);
            } else if (i == "/") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 / op1);
            } else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
