class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    unordered_map<int,int> mp;
    stack<int> st;
    //finding next greator of nums 2 store in the map using map fill the element of according to nums1 using map
    for(int i=m-1;i>=0;i--){
        while(st.size()>0 && st.top()<=nums2[i]){
            st.pop();
        }
        if(st.size()==0) mp[nums2[i]]=-1;
        else mp[nums2[i]]=st.top();
        st.push(nums2[i]);
    }
    // fill the answer
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
    }
};