class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dictionary = defaultdict(list)
        for i in strs:
            chars = [0] * 26
            for j in i:
                chars[ord(j) - 97] += 1
            key = tuple(chars)
            dictionary[key].append(i)
        return list(dictionary.values())
