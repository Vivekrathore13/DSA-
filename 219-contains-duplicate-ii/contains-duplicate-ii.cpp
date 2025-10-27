#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.count(nums[i]) && i - lastIndex[nums[i]] <= k) {
                return true;
            }
            lastIndex[nums[i]] = i; // update latest index
        }
        return false;
    }
};
