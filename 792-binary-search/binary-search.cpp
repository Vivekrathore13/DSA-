class Solution {
public:
    int binary(vector<int>& nums, int lo, int hi, int tar){
        
        if(lo > hi) return -1;

        int mid = lo + (hi - lo) / 2;

        if(nums[mid] == tar){
            return mid;
        }
        else if(nums[mid] < tar){
            return binary(nums, mid + 1, hi, tar);
        }
        else{
            return binary(nums, lo, mid - 1, tar);  // ✅ return added
        }
    }

    int search(vector<int>& nums, int target) {
        return binary(nums, 0, nums.size() - 1, target); 
    }
};