class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    int n=nums.size();
    int count=0;
    int ma=INT_MIN;
    unordered_map<int,int> mp;
    for(int ele:nums){
        mp[ele]++;
        ma=max(ma,mp[ele]);
    }    

    for(auto el:mp){
        if(el.second==ma){
            count+=el.second;
        }
    }
    return count;
    }
};