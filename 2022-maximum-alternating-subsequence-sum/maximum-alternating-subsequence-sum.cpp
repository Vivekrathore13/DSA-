class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // DP table: t[i][0] = negative phase, t[i][1] = positive phase
        vector<vector<long long>> t(n + 1, vector<long long>(2, 0));

        for (int i = 1; i <= n; i++) {
            // If we subtract current element (negative phase)
            t[i][0] = max(t[i - 1][1] - nums[i - 1], t[i - 1][0]);

            // If we add current element (positive phase)
            t[i][1] = max(t[i - 1][0] + nums[i - 1], t[i - 1][1]);
        }

        // Return maximum possible alternating sum
        return max(t[n][0], t[n][1]);
    }
};
