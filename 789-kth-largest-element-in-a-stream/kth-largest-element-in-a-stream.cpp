#include <queue>
#include <vector>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int K;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > K) pq.pop(); // maintain size = k
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top(); // kth largest
    }
};
