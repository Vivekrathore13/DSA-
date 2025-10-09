/*
 * Time Complexity: O(n), where n is the size of nums. Each state (idx, flag) is computed exactly once due to memoization.
 * Space Complexity: O(n), due to the DP memoization table of size n x 2 and recursion stack depth up to O(n).
 */
class Solution {
public:
    int n;  // Store the size of nums for reuse
    typedef long long ll;  // Alias for long long to handle large sums
    ll t[1000001][2];  // Memoization table: t[idx][flag] stores the max alternating sum from idx with current sign flag (0: negative, 1: positive)

    // Recursive helper function to compute the maximum alternating sum starting from index idx, with current sign determined by flag (true: positive, false: negative)
    ll solve(int idx, vector<int>& nums, bool flag) {
        if (idx >= n) {  // Base case: reached end of array, no more elements to add
            return 0;
        }

        // Check if this state (idx, flag) is already memoized
        if (t[idx][flag] != -1)
            return t[idx][flag];

        // Option 1: Skip current element, proceed to next with same flag (sign)
        ll skip = solve(idx + 1, nums, flag);

        // Prepare the value of current element with sign based on flag
        ll val = nums[idx];
        if (flag == false) {  // If flag is false, treat current as negative
            val = -val;
        }

        // Option 2: Take current element with its sign, flip flag for next element, and add to recursive result
        ll take = solve(idx + 1, nums, !flag) + val;

        // Memoize and return the maximum of skip or take
        return t[idx][flag] = max(skip, take);
    }

    // Main function to compute the maximum alternating subarray sum
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();  // Get the size of the input array
        memset(t, -1, sizeof(t));  // Initialize memoization table with -1 to indicate uncomputed states
        return solve(0, nums, true);  // Start from index 0 with positive sign (flag = true)
    }
};