class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int> mp;
    vector<int> v;

    for(int ele:nums){
        mp[ele]++;
    }  

    for(auto el:mp){
        int x=el.second;
        int y=el.first;
        if(x==2){
            v.push_back(y);
        }
    }
    return v;
    }
};