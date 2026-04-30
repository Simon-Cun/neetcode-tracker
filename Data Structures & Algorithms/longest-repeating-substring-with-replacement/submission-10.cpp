class Solution {
public:
    int characterReplacement(string s, int k) {
        // initialize our hashmap, left pointer, return value, current largest element
        // loop through our string and appned to our hashMap our frequency of values
        // if we go over our k which means (r - l + 1) - current largest > k then we have to pop
            // in this if statement we will pop our l and check if r - l + 1 - currlargest in a while look and keep doing that
            //in the loop we also have to update our current return value and curr max if we find a bigger thing

        unordered_map<char, int> freqMap;
        int ret = 0;
        int currMax = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            ++freqMap[s.at(r)];
            currMax = max(currMax, freqMap[s.at(r)]);
            while ((r - l + 1) - currMax > k) {
                --freqMap[s.at(l)];
                ++l;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
