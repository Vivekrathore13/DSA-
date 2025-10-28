class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int count = 0;

        for (int start = 0; start < n; start++) {
            if (nums[start] == 0) {
                // Try both directions
                if (isValid(nums, start, 1)) count++;
                if (isValid(nums, start, -1)) count++;
            }
        }

        return count;
    }

    private boolean isValid(int[] nums, int start, int dir) {
        int n = nums.length;
        int[] arr = nums.clone();
        int curr = start;
        int d = dir;

        while (curr >= 0 && curr < n) {
            if (arr[curr] == 0) {
                curr += d;  // move in same direction
            } else {
                arr[curr]--;   // decrement
                d = -d;        // reverse direction
                curr += d;     // move one step
            }
        }

        // check if all zeros
        for (int x : arr) {
            if (x != 0) return false;
        }
        return true;
    }
}
