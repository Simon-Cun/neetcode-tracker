#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (int i = 0; i < s.size(); ++i) {
            if ((isalpha(s[i]) || isalnum(s[i]))) {
                newStr += tolower(s[i]);
            }
        }
        for (int i = 0; i < (int)(newStr.size() / 2); ++i) {
            
            if (newStr[i] != newStr[newStr.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
