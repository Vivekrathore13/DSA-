class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int ele:nums){
        mp[ele]++;
    }  
    int x;
    int y;  
    for(auto m:mp){
        y=m.second;
        if(y>n/3){
            ans.push_back(m.first);
        }
    }
    return ans;
    }
};