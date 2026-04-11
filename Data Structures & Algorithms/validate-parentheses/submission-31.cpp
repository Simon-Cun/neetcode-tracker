#include <stack>
#include <unordered_map>
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> openToClose = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;
        for (const auto& i : s) {
            if (openToClose.contains(i)) {
                st.push(i);
            } else if (st.empty() || i != openToClose.at(st.top())) {
                return false;
            } else if (i == openToClose.at(st.top())) {
                st.pop();
            }
        }
        return st.empty();
    }
};
