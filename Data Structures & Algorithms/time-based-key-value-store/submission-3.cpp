#include <unordered_map>
#include <utility>
#include <string>
class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> hashMap;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& arr = hashMap[key];
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m].second == timestamp) {
                return arr[m].first;
            } else if (arr[m].second < timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (r < 0) {
            return "";
        }
        return arr[r].first;
    }
};
