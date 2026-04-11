class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (const auto& i : s) {
            if (isalpha(i) or isalnum(i)) {
                str += tolower(i);
            }
        }
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
