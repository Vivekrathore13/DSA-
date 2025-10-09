class Solution {
public:
    int n;
    int dp[2501][2501]; // dp[i][p] stores LIS starting from index i with previous index p

    // Recursive function to compute LIS
    int solve(vector<int>& nums, int i, int p) {
        if (i >= n) return 0;

        // If already computed
        if (p != -1 && dp[i][p] != -1) return dp[i][p];

        int take = 0;
        // Option 1: Take current element (if increasing)
        if (p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(nums, i + 1, i);
        }

        // Option 2: Skip current element
        int skip = solve(nums, i + 1, p);

        // Store in dp (only when p != -1)
        if (p != -1)
            dp[i][p] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};