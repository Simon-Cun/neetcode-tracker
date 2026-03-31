class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dictionary = {}
        for i in nums:
            dictionary[i] = dictionary.get(i, 0) + 1
        result = []
        for i in range(k):
            result.append(max(dictionary, key=dictionary.get))
            del dictionary[max(dictionary, key=dictionary.get)]
        return result