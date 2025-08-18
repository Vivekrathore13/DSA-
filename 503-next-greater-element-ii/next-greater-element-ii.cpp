class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n,0);
    stack<int> st;
    // to solve this question think like same array is present then 
    // to map the element use i%n and loop start with 2*n-1
    for(int i=2*n-1;i>=0;i--){
        while(st.size()>0 && nums[st.top()]<=nums[i%n]){
            st.pop();
        }
        ans[i%n]= st.empty() ? -1 : nums[st.top()];
        st.push(i%n);
    }   
    return ans;
    }
};