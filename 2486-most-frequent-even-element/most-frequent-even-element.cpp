class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;

        // count frequency of even numbers
        for(int ele : nums){
            if(ele % 2 == 0){
                mp[ele]++;
            }
        }

        int ans = -1;        // if no even number exists
        int maxFreq = 0;

        for(auto &p : mp){
            int element = p.first;
            int count = p.second;

            if(count > maxFreq || (count == maxFreq && element < ans)) {
                maxFreq = count;
                ans = element;
            }
        }

        return ans;
    }
};
