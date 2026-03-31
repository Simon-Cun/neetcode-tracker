class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dictionary = {}
        for i in nums:
            if i in dictionary:
                dictionary[i] += 1
            else:
                dictionary[i] = 1
        myList = list()
        for j in range(k):
            maxKey = max(dictionary, key=dictionary.get)
            myList.append(maxKey)
            del dictionary[maxKey]
        return myList
