class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: copy nums2 elements into nums1 starting from index m
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        // Step 2: sort nums1
        sort(nums1.begin(), nums1.end());
    }
};
