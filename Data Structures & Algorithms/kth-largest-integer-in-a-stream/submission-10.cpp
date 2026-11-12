class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) : k(k), pq(nums.begin(), nums.end()) {
        if (nums.size() < k) return;
        for (int i = 0; i < nums.size() - k; ++i) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > k) pq.pop();
        return pq.top();
    }
};
