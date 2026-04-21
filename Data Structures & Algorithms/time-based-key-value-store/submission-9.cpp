class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hashMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = hashMap[key].size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            pair<int, string> value = hashMap[key][m];
            if (value.first == timestamp) {
                return value.second;
            } else if (value.first < timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r >= 0 ? hashMap[key][r].second : "";
    }
};
