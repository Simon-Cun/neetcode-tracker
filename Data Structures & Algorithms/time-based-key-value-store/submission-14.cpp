class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end()) return "";
        int l = 0, r = hash[key].size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (timestamp == hash[key].at(m).first) {
                return hash[key].at(m).second;
            } else if (timestamp < hash[key].at(m).first) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (r < 0) return "";
        return hash[key].at(r).second;
    }
};
