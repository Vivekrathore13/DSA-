class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int ele:nums){
        mp[ele]++;
    }   
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto &n:mp){
        int x=n.first,freq=n.second;
        pq.push({freq,-x});
    }
    vector<int> ans;
    while(!pq.empty()){
        int freq=pq.top().first;
        int val=-pq.top().second;
        pq.pop();
        for(int i=0;i<freq;i++){
            ans.push_back(val);
        }
    }
    return ans;
    
    }
};