class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> posSpe;
        for (int i = 0; i < position.size(); ++i) {
            posSpe.push_back({position.at(i), speed.at(i)});
        }
        sort(posSpe.begin(), posSpe.end());
        stack<double> st;
        for (int i = 0; i < posSpe.size(); ++i) {
            double curr = (target - posSpe.at(i).first) / (double)posSpe.at(i).second;
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            st.push(curr);
        }
        return st.size();
    }
};
