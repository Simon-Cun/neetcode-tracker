class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (auto& i : s) {
            if ('a' <= i && i <= 'z' || '0' <= i && i <= '9') {
                str += i;
            } else if ('A' <= i && i <= 'Z') {
                str += (i ^ 32);
            }
        }
        for (int i = 0; i < str.size() / 2; ++i) {
            if (str.at(i) != str.at(str.size() - 1 - i)) return false;
        }
        return true;
    }
};
