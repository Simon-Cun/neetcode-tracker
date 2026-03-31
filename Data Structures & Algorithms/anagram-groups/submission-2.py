class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dictionary = defaultdict(list)
        for i in strs:
            chars = [0] * 26
            for j in i:
                chars[ord(j) - ord('a')] += 1
            dictionary[tuple(chars)].append(i)
        return list(dictionary.values())
