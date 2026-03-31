class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        char_freq = [0] * 26
        left = 0
        longest = 0
        freq = 0
        for i in range(len(s)):
            index = ord(s[i]) - ord('A')
            char_freq[index] += 1
            freq = max(char_freq)
            while (i - left + 1) - freq > k:
                char_freq[ord(s[left]) - ord('A')] -= 1
                left += 1
            longest = max(longest, i - left + 1)
        return longest
