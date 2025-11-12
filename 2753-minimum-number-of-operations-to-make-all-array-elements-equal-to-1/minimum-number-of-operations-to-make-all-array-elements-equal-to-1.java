class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int count1 = 0;

        // Step 1: Count number of 1s
        for (int x : nums) {
            if (x == 1) count1++;
        }

        // Case 1: Already have some 1s
        if (count1 > 0) {
            return n - count1;
        }

        // Case 2: No 1s, find smallest subarray with gcd = 1
        int best = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    best = Math.min(best, j - i + 1);
                    break; // No need to extend further
                }
            }
        }

        // If no subarray gives gcd 1, impossible
        if (best == Integer.MAX_VALUE) return -1;

        // (best - 1) ops to create first 1, then (n - 1) to spread
        return (best - 1) + (n - 1);
    }

    // Helper function for gcd
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}
