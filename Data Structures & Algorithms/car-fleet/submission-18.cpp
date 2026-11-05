class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < position.size(); ++i) {
            arr.push_back({position.at(i), speed.at(i)});
        }
        sort(arr.begin(), arr.end());
        stack<double> st;
        for (int i = 0; i < arr.size(); ++i) {
            double distToEnd = (target - arr.at(i).first) / (double)arr.at(i).second;
            while (!st.empty() && distToEnd >= st.top()) {
                st.pop();
            }
            st.push(distToEnd);
        }
        return st.size();
    }
};
