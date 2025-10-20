class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        int j = 0; 
        int maxc = 0;

        while (j < n) {
            if (nums[j] == 1) {
                // expand the window to the right
                maxc = max(maxc, j - i + 1);
                j++;
            } else {
                // reset window starting after the zero
                j++;
                i = j;
            }
        }
        return maxc;
    }
};
