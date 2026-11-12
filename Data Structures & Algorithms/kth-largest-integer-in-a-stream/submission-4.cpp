class KthLargest {
public:
    vector<int> stream;
    int kth;
    KthLargest(int k, vector<int>& nums) : kth(k), stream(nums) {
        
    }
    
    int add(int val) {
        stream.push_back(val);
        priority_queue<int> pq(stream.begin(), stream.end());
        int count = kth - 1;
        while (count) {
            pq.pop();
            --count;
        }
        return pq.top();
    }
};
