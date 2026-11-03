class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
        stack<char> st;
        for (auto& i : s) {
            if (hash.find(i) != hash.end()) {
                st.push(i);
            } else {
                if (!st.empty() && hash[st.top()] == i) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
