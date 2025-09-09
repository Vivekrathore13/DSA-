class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(auto ele:nums){
        mp[ele]++;
    }    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto n:mp){
        int x=n.first,freq=n.second;
        pq.push({freq,x});
        if(pq.size()>k) pq.pop();
    }
    vector<int> ans;
    while(pq.size()>0){
        int ele=pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    return ans;
    }
};