class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)

        for i in strs:
            chars = [0] * 26
            for j in i:
                chars[ord(j) - ord('a')] += 1
            d[tuple(chars)].append(i)

        return list(d.values())
