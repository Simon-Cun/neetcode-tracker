class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;
        for (auto& i : s) {
            if (hash.contains(i)) st.push(i);
            else if (st.empty() or hash[st.top()] != i) return false;
            else st.pop();
        }
        return st.empty();
    }
};
