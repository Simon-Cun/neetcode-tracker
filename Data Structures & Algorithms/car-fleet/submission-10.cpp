#include <utility>
#include <vector>
#include <stack>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> tarPos;
        for (int i = 0; i < position.size(); ++i) {
            tarPos.push_back(make_pair(position[i], speed[i]));
        }
        sort(tarPos.begin(), tarPos.end());

        stack<double> st;
        for (auto& p : tarPos) {
            double currSpeed = (double)(target - p.first) / p.second;
            while (true) {
                if (st.empty()) {
                    st.push(currSpeed);
                    break;
                } else if (st.top() <= currSpeed) {
                    st.pop();
                } else {
                    st.push(currSpeed);
                    break;
                }
            }
        }
        return st.size();
    }
};
