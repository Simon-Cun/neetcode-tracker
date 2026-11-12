class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, int>> arr;
        for (int i = 0; i < points.size(); ++i) {
            arr.push_back({(sqrt(pow(points.at(i).at(0), 2) + pow(points.at(i).at(1), 2))), i});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq(arr.begin(), arr.end());
        vector<vector<int>> ret;
        while (k) {
            ret.push_back(points.at(pq.top().second));
            pq.pop();
            k--;
        }
        return ret;
    }
};
