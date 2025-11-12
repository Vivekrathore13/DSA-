class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for (int x : nums)
            if (x == 1) cnt1++;
        
        // Case 1: if already have 1s
        if (cnt1 > 0)
            return n - cnt1;

        // Case 2: no 1s, find smallest subarray with gcd == 1
        int best = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    best = min(best, j - i + 1);
                    break;  // no need to extend further
                }
            }
        }

        if (best == INT_MAX) return -1; // impossible
        return best - 1 + n - 1; // (to create 1) + (to spread 1)
    }
};
