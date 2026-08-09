class Solution {
public:
    bool isPalindrome(string s) {
        string processedStr = "";
        for (auto& i : s) {
            if (isalpha(i) || isdigit(i)) {
                processedStr += (i | 32);
            }
        }
        cout << processedStr;
        for (int i = 0; i < processedStr.size() / 2; ++i) {
            if (processedStr.at(i) != processedStr.at(processedStr.size() - i - 1)) return false;
        }
        return true;
    }
};
