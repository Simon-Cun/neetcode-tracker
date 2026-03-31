class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dictionary = {}
        res = []
        for i in nums:
            dictionary[i] = dictionary.get(i, 0) + 1
        for _ in range(k):
            res.append(max(dictionary, key=dictionary.get))
            del dictionary[max(dictionary, key=dictionary.get)]
        return res