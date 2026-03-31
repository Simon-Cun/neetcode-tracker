class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        dictionary = {}
        output = 0
        biggestOutput = 0
        for i in nums:
            if i in dictionary:
                dictionary[i] += 1
            else:
                dictionary[i] = 1
        print(dictionary)
        smallest_key = min(dictionary)
        output = 1
        biggestOutput = output
        del dictionary[smallest_key]
        num = smallest_key
        newdict = {}
        while dictionary:
            num += 1
            
            if num not in dictionary:
                smallest_key = min(dictionary)
                del dictionary[smallest_key]
                num = smallest_key
                output = 1
            else:
                output += 1
                newdict[num] = dictionary[num]
                del dictionary[num]
            if biggestOutput < output:
                biggestOutput = output
        return biggestOutput
                
            