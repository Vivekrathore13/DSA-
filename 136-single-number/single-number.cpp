class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map<int,int> mp;

    for(auto x:nums){
        mp[x]++;
    }   
    int z;
    for(auto &n:mp){
        int m=n.second;
        if(m==1){
            z=n.first;
        }
        else continue;
    }
    return z;
    }
};