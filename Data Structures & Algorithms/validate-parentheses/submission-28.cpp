#include <stack>
#include <unordered_map>
#include <string>
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> openToClose{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;
        for (auto& str : s) {
            if (openToClose.contains(str)) {
                st.push(str);
            } else {
                if (st.empty() or str != openToClose[st.top()]) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
