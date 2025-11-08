class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;  // Already valid if length <= 2

        int i = 2;  // Start from 3rd element
        for (int j = 2; j < n; j++) {
            // Only copy if current num is not the same as nums[i-2]
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;  // New length
    }
};
